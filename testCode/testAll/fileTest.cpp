	CStdioFile stdFile;
	enum class Color
	{
		red,
		blue,
		green
	};
	//循环打开三个不同的文件
	CString fileName;
	for (int i = int(Color::red); i <= int(Color::green); i++)
	{
		switch (Color(i))
		{
		case Color::red:
			fileName = L"D:\\R.csv";
			stdFile.Open(fileName, CFile::modeWrite | CFile::modeCreate /*| CFile::osWriteThrough*/);
			break;
		case Color::blue:
			fileName = L"D:\\B.csv";
			stdFile.Open(fileName, CFile::modeWrite | CFile::modeCreate /*| CFile::osWriteThrough*/);
			break;
		case Color::green:
			fileName = L"D:\\G.csv";
			stdFile.Open(fileName, CFile::modeWrite | CFile::modeCreate /*| CFile::osWriteThrough*/);
			break;
		default:
			break;
		}
		CStringA str;
		for(int row  = 0; row < 1000; ++row)
			for (int col = 0; col < 1000; col++)
			{
				str.Format("%d,%d,%d,%d,%d\n", col, col, col, col, col);
				stdFile.Write(str, str.GetLength());
			}
		stdFile.Close();
	}

    //vs2022无法复现三个文件全部写入同一文件的情况