#include <iostream>
#include <string>
#include <vector>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#pragma once
#include "..\..\..\Net\Include\p2pclientlib.h"
#include "..\..\..\Net\Include\P2PServerExport.h"
#include "..\..\Include\ICaliNet.h"

//效果调试多工位传输的数据格式
enum enEDMultiStationDataPackType
{
	enInvalid = 0,
	enServer2Client_BoxName = 1001,
	enClient2Server_CaliPrj = 1002,
	enStationDataPackTypeCount = 2,
};

struct SMultiStationNetDataPack
{
	WORD	packType;
	BYTE	pData[0];	//数据内容

	SMultiStationNetDataPack()
	{
		packType = enEDMultiStationDataPackType::enInvalid;
	}
};

//事件类型
enum EnEventType
{
	enAddBox,
    enUpdatePrj,
	enCount
};

//工位事件
struct SStationEvent
{
	EnEventType type;
	CString boxName;
};

//需要传输的数据
struct SMultiStationTranInfo
{
	CString strInfo;		//服务端：箱体名， 客户端：工程路径
	CString IP2Send;		//需要发送到的IP地址

	SMultiStationTranInfo() = default;

	SMultiStationTranInfo(CString str, CString ip = _T("")) :
		strInfo(str),
		IP2Send(ip)
	{
	}
};

interface IStationEventWatcher
{
	virtual HRESULT NotifyStationEvent(SStationEvent stationEvent) PURE;

	EnStationType	m_stationType;	   //机器类型
};

class CStationService : public IP2PServerNotify, public IP2PClientNotify
{
public:
	CStationService();
	~CStationService();

	HRESULT						InitService();
	void						ReleaseService();

	virtual HRESULT				OnP2PNotify(DWORD dwConnection, DWORD dwType, int nDataLen, void* lpData);

	HRESULT						Connect();
	HRESULT						DisConnect();
	BOOL						IsConnected();
	HRESULT						SetNotify(IStationEventWatcher* watcher);

	//client
	void						ClientAddCaliPrj(CString prjPath);
	HRESULT						ClientDisconnect();

	//添加需要传输的数据
	void						AddTranInfo(CString strInfo, CString targetIP = _T(""));	//只有服务端需要添加目标IP

private:
	//server
	HRESULT						OnServerNotify(DWORD dwConnection, DWORD dwType, int nDataLen, void* lpData);

	//client
	HRESULT						OnClientNotify(DWORD dwConnection, DWORD dwType, int nDataLen, void* lpData);

	void						AddClientConnect(SLiveClient* liveClient);				//添加连接   客户端-->服务端
	static UINT					ClientReconnectThread(LPVOID lpVoid);	//客户端与服务端断连后自动重连线程
	HRESULT						ClientReconnect();
    
	//Common
	HRESULT						SendStationInfo();
	static UINT					SendStationInfoThread(LPVOID lpVoid);	//多工位循环发送数线程
	SMultiStationNetDataPack*	InitVSNNetDataPack(int type, int length);
	void						InitSendInfoThread();
	HRESULT						DestroyP2PClient();

private:
	IP2PServer*					m_pP2PServer;
	IP2PClient*					m_pP2PClient;
	SStationInfo				m_sStationInfo;		//当前的机器类型
	std::vector<IStationEventWatcher*> m_vecEventWatcher;

	//服务端（上料机）
	CWinThread*					m_trdSendStationInfo;
	BOOL						m_bRunningSend;	    //开启发送箱体名线程
	std::map<CString, DWORD>	m_mapBinding;		//已连接的IP与连接标识绑定
	
	//客户端(非上料机)
	CWinThread*					m_trdReconnect;
	BOOL						m_bRunningReconnect;//开启尝试重连

	CWinThread*					m_trdSendCaliPrj;
	BOOL						m_bRunningSendPrj;	//开启发送工程线程

	SLiveClient*				m_pCurClient;		//当前通信的服务端参数
	CMutex						m_mtxQueue;

	std::queue<SMultiStationTranInfo>	m_qStationTranInfo;
};

inline int GetNetDataPackLen(int bufLen)
{
	return sizeof(SMultiStationNetDataPack) + bufLen;
}