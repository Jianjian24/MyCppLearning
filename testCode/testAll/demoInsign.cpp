
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