
HRESULT CCSVFile::LoadFromCSV(CString filePath)
{
	m_csvFileData.RemoveAll();

	CStdioFileEx stdFile;
	if(!stdFile.Open(filePath, CFile::modeRead | CFile::typeText))
		return T9E_FILE_CREATE_ERROR;

	int rows 	 = 0;
	int cols 	 = 0;
	int colsTemp = 0;
	int index	 = -1;
	CString strTemp;
	//计算文件中CSV数据的行列数
	while(stdFile.ReadString(strTemp))
	{
		rows++;									//记录行数
		index = strTemp.Find(_T(','));
		while(-1 != index)
		{
			colsTemp++;
			strTemp = strTemp.Mid(index+1);
			index   = strTemp.Find(_T(','));
		}

		if(!strTemp.IsEmpty())
			colsTemp++;

		if(colsTemp > cols)
			cols = colsTemp;				   //记录列数

		colsTemp = 0;
	}
	
	if(rows < 1 || cols < 1)
		return T9E_NOT_SUPPORT;				//不支持的文件格式

	//导入CSV数据
	CString rowStr;
	int		colCount = 0;
	stdFile.SeekToBegin();
	SetCSVFileRowsAndCols(rows, cols);
	for(int i = 0; i < m_rows; i++)
	{
		if(!stdFile.ReadString(rowStr))					//判断行结束
			break;

		for(int j = 0; j < m_cols; j++)
		{
			colCount = rowStr.Find(_T(','));
			CString strTemp;
			strTemp = rowStr.Left(colCount);
			strTemp.Replace(_T("*"),_T(","));
			if(-1 != colCount)						   //判断列结束
			{
				m_csvFileData[i * m_cols + j] = strTemp;
				rowStr = rowStr.Mid(colCount + 1);
			}
			else
			{
				rowStr.Trim();						   //清除 \r\n 换行
				if(!rowStr.IsEmpty())				   //判断行尾是否有数据
				m_csvFileData[i * m_cols + j] = rowStr;

				break;
			}
		}
	}

	return T9_S_OK;
}


//提示输出
GetDlgItem(nCtrlID[id])->GetWindowText(strContent);
if (strContent.Compare(strContent.SpanIncluding(_T("0123456789.默认值Default"))) != 0)
{
	if (id < 4 && strContent.Compare(strContent.SpanIncluding(_T("0123456789.默认值Default"))) != 0)
	{
		CString strText = g_translate.TranslateString(_T("Tools_Only_Numbers_Can_Input"));
		G_ShowBalloonTip(GetDlgItem(nCtrlID[id])->GetSafeHwnd(), tagTip, strText, strTitle, TTI_INFO);
		bValid = FALSE;
	}
		break;
}

//关于梯度的二维数组
21	 std::vector<float>   m_fVecUpGradient[whiteColor];    //上边缘梯度 
22	 std::vector<float>   m_fVecDownGradient[whiteColor];    //下边缘梯度 
23	 std::vector<float>   m_fVecLeftGradient[whiteColor];    //左边缘梯度 
24	 std::vector<float>   m_fVecRightGradient[whiteColor];   //右边缘梯度

float CCalibrationSetting::GetEdgeGradient(int nRow, EnGradientDirection type, int nColor)
{
	switch (type)
	{
	case enUp:
		return m_fVecUpGradient[nColor][nRow];
	case enDown:
		return m_fVecDownGradient[nColor][nRow];
	case enLeft:
		return m_fVecLeftGradient[nColor][nRow];
	case enRight:
		return m_fVecRightGradient[nColor][nRow];
	default:
		ASSERT(0);
		break;
	}
	return 0;
}


//灯点xp结构体
struct SCaliModuleInfo
{
	int			m_nRowOfBlock;	//模组所在的分区行序号
	int			m_nIndex;		//模组在分区内的序号
	int			m_nRow;			//模组行数
	std::vector<int> m_vecCount;		//每行灯点个数
	SCaliModuleInfo()
	{
		m_nRow = 0;
		m_nRowOfBlock = 0;
		m_nIndex = 0;
	}

	SCaliModuleInfo& operator = (SCaliModuleInfo& other)
	{
		if (this == &other)
			return *this;
		m_nIndex = other.m_nIndex;
		m_nRowOfBlock = other.m_nRowOfBlock;
		m_nRow = other.m_nRow;
		if (other.m_vecCount.size() > 0)
		{
			m_vecCount.resize(other.m_vecCount.size());
			m_vecCount.assign(other.m_vecCount.begin(), other.m_vecCount.end());
		}
	}

	bool operator > (SCaliModuleInfo& other)
	{
		if (m_nRowOfBlock > other.m_nRowOfBlock)
			return true;
		else if (m_nRowOfBlock == other.m_nRowOfBlock && m_nIndex > other.m_nIndex)
			return true;
		else
			return false;
	}

	bool operator == (SCaliModuleInfo& other)
	{
		if (m_nRowOfBlock == other.m_nRowOfBlock && m_nIndex == other.m_nIndex)
			return true;
		else
			return false;
	}
};

typedef std::vector<SCaliModuleInfo>	VecSCaliModuleInfo;