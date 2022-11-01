int timeJudge(int year, int month, int day)//ʱ���жϺ��������������ڵ�ʱ���
{
	size_t now_time = 0, set_time = 0;
	struct tm q;
	q.tm_year = year-1900;
	q.tm_mon = month-1;
	q.tm_mday = day;
	q.tm_hour = 0;
	q.tm_min = 0;
	q.tm_sec = 0;
	q.tm_isdst = 0;
	set_time = mktime(&q);
	time(&now_time);
	return now_time - set_time;
}
