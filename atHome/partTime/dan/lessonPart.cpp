#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define max_users 100
#define max_courses 100
#define max_students 100
#define max_length 50
#define max_enroll_course 4
#define requiredCredits 100

//定义结构体
//用户信息
typedef struct {
	char username[max_length];
	char password[max_length];
} User;

//课程信息
typedef struct {
	char name[max_length];
	int hours;
	char major[max_length];
	int credits;
	int numStudents;
} Course;

//学生信息
typedef struct {
	int id;
	char name[max_length];
	char major[max_length];
	int numCourses;
	char courses[max_enroll_course][max_length];
} Student;

//全局变量
User users[max_users];
int numUsers = 0;
Course courses[max_courses];
Student students[max_students];

//声明函数
void loadCoursesFromFile(int*);
void loadStudentsFromFile(int*);
void loadUsersFromFile();
int loadNumCoursesFromFile();
int loadNumStudentsFromFile();
void mainMenu();
void registerUser();
int loginUser();
void adminMenu();
void studentMenu();
int saveCoursesToFile();
int saveStudentsToFile();
void saveNumCoursesToFile(int);
void saveNumStudentsToFile(int);
void adminLogin();
void studentLogin();
void courseInfoMenu();
void studentInfoMenu();
void enrollmentMenu();
void addCourse();
void deleteCourse();
void updateCourse();
void queryCourses();
void addStudent();
void deleteStudent();
void updateStudent();
void queryStudent();
void displayCourse(Course course);
void querySingleCourse();
void queryAllCourses();
void queryCourseByMajor();
void displayStudent(Student student);
void querySingleStudent();
void queryAllStudents();
void queryStudentByMajor();
void resetPassword(const char* username);
void enrollCourse();
void dropCourse();
void displayOneself();

//主函数
int main()
{
	int numCourses = loadNumCoursesFromFile();
	int numStudents = loadNumStudentsFromFile();
	//从文件加载课程信息
	loadCoursesFromFile(&numCourses);
	//从文件加载学生信息
	loadStudentsFromFile(&numStudents);
	//从文件加载用户信息
	loadUsersFromFile();

	printf("====欢迎使用学生选课信息管理系统！====\n");
	//主菜单
	mainMenu();

	return 0;
}

//从文件加载课程信息
void loadCoursesFromFile(int* numCourses)
{
	FILE* file = fopen("courses.txt", "rb");
	if (file == NULL)
	{
		printf("无法打开该文件！\n");
		return;
	}

	int countCourse = 0;
	while ((countCourse < *numCourses) && countCourse < max_students)
	{
		fread((courses + countCourse), sizeof(Course), 1, file);
		++countCourse;
	}


	// *numCourses = 0; // 更新课程总数

	// while ((*numCourses) < max_courses && fscanf(file, "%[^,],%d,%d,%[^,\n]", courses[*numCourses].name, &(courses[*numCourses].hours), &(courses[*numCourses].credits), courses[*numCourses].major) >= 3)
	// {
	// 	// 尝试读取 numStudents 值
	// 	int result = fscanf(file, ",%d", &(courses[*numCourses].numStudents));
	// 	if (result < 1)
	// 	{
	// 		// 如果无法成功读取 numStudents，则将其设为默认值 0
	// 		courses[*numCourses].numStudents = 0;

	// 		// 清除文件中的多余字符，直到换行符为止
	// 		while (fgetc(file) != '\n')
	// 		{
	// 			continue;
	// 		}
	// 	}

	// 	(*numCourses)++;
	// }

	// if ((*numCourses) == max_courses && !feof(file))
	// {
	// 	printf("课程数量达到最大值！\n");
	// }

	fclose(file);
}

//从文件加载学生信息
void loadStudentsFromFile(int* numStudentsPtr)
{
	FILE* file = fopen("students.txt", "rb");
	if (file == NULL)
	{
		printf("无法打开该文件！\n");
		return;
	}

	// *numStudentsPtr = 0; // 更新学生总数 ???? 先注释掉
	int result;
	int countStu = 0;
	while ((countStu < *numStudentsPtr) && countStu < max_students)
	{
		fread((students + countStu), sizeof(Student), 1, file);
		++countStu;
	}
	

	// 使用循环读取学生数据，直到达到最大学生数或文件末尾
	// while ((*numStudentsPtr) < max_students && (fscanf(file, "%d,%[^,],%[^,\n],%d", &students[*numStudentsPtr].id, students[*numStudentsPtr].name, students[*numStudentsPtr].major, &students[*numStudentsPtr].numCourses)) >= 4)
	// {
	// 	if (students[*numStudentsPtr].numCourses > 0)
	// 	{
	// 		for (int i = 0; i < students[*numStudentsPtr].numCourses; i++)
	// 		{
	// 			result = fscanf(file, ",%[^,\n]", students[*numStudentsPtr].courses[i]);
	// 			if (result != 1)
	// 			{
	// 				// 如果无法成功读取选课信息，则将其设为默认值空字符串
	// 				strcpy(students[*numStudentsPtr].courses[i], "");
	// 			}
	// 		}
	// 	}

	// 	(*numStudentsPtr)++;
	// }

	// if ((*numStudentsPtr) == max_students && !feof(file))
	// {
	// 	printf("学生数量达到最大值！\n");
	// }

	fclose(file);
}

//从文件加载用户信息
void loadUsersFromFile()
{
//改为二进制读取

	//二进制方式打开文件
	int size = 0;
	char *ar = nullptr;
 
	FILE *fp = fopen("users.txt","rb");
	if(NULL == fp)
	{
		printf("Error!! file fail!\n");
		return;
	}
 
	//求得文件的大小
	fseek(fp, 0, SEEK_END);
	size = ftell(fp);
	rewind(fp);

	int userCount = size / sizeof(User);

	while (numUsers < userCount && numUsers < max_users)
	{
		//users[numUsers].username, users[numUsers].password
		fread((users + numUsers), sizeof(User), 1, fp);
		++numUsers;
	}

	if (numUsers == max_users)
	{
		printf("用户数量达到最大值！\n");
	}
	fclose(fp);
//======================
	// FILE* file = fopen("users.txt", "r");
	// if (file == NULL)
	// {
	// 	printf("无法打开该文件！\n");
	// 	return;
	// }
	// numUsers = 0;
	// while (numUsers <= max_users && fscanf(file, "%s %s", users[numUsers].username, users[numUsers].password) == 2)
	// {
	// 	numUsers++;
	// }

	// if (numUsers == max_users && !feof(file))
	// {
	// 	printf("用户数量达到最大值！\n");
	// }
	// fclose(file);
}

//从文件加载课程总数信息
int loadNumCoursesFromFile()
{
	FILE* file = fopen("num_courses.txt", "rb");
	if (file == NULL)
	{
		// 文件打开失败，返回默认的课程总数
		return 0;
	}

	int numCourses;
	fread(&numCourses, sizeof(int), 1, file);
	// int result = fscanf(file, "%d", &numCourses);
	fclose(file);

	// if (result != 1)
	// {
	// 	// 读取课程总数失败，返回默认的课程总数
	// 	return 0;
	// }

	return numCourses >= 0 ? numCourses : 0;
}

//从文件加载学生总数
int loadNumStudentsFromFile()
{
	FILE* file = fopen("num_students.txt", "rb");
	if (file == NULL)
	{
		// 文件打开失败，返回默认的学生总数
		return 0;
	}

	int numStudents;
	fread(&numStudents, sizeof(int), 1, file);
	// int result = fscanf(file, "%d", &numStudents);
	fclose(file);

	// if (result != 1)
	// {
	// 	// 读取学生总数失败，返回默认的学生总数
	// 	return 0;
	// }

	return numStudents >= 0 ? numStudents : 0;
}

//主菜单
void mainMenu()
{
	int choice;
	int result;

	do {
		printf("======================================\n");
		printf("               1.注册\n");
		printf("               2.登录\n");
		printf("               3.退出\n");
		printf("======================================\n");
		printf("请输入您的选择：");
		result = scanf("%d", &choice);

		if (result != 1)
		{
			printf("输入选择失败！\n");
			return;
		}

		switch (choice)
		{
		case 1:
			registerUser();
			break;
		case 2:
			if (loginUser())
			{
				if (strcmp(users[numUsers - 1].username, "admin") == 0)
				{
					adminMenu();
				}
				else
				{
					studentLogin();
				}
			}
			break;
		case 3:
			saveCoursesToFile();
			saveStudentsToFile();
			printf("感谢您的使用！\n");
			printf("======================================\n");
			exit(0);
		default:
			printf("无效选项，请再次尝试！\n");
		}
	} while (choice != 3);
}

//用户注册
void registerUser()
{
	int result;
	char username[max_length], password[max_length], captcha[max_length];

	printf("==============<用户注册>==============\n");
	printf("请输入用户名（用户名为学生学号）：");
	result = scanf("%s", username);
	username[max_length - 1] = '\0';

	if (result != 1)
	{
		printf("用户名输入失败！\n");
		return;
	}

	for (int i = 0;i < numUsers;i++)
	{
		if (strcmp(users[i].username, username) == 0)
		{
			printf("该用户名已存在！请直接登录或重新注册！\n");
			return;
		}
	}
	printf("请输入密码：");
	result = scanf("%s", password);
	password[max_length - 1] = '\0';
	if (result != 1)
	{
		printf("输入密码错误！\n");
		return;
	}

	printf("请输入验证码：");
	result = scanf("%s", captcha);
	captcha[max_length - 1] = '\0';
	if (result != 1)
	{
		printf("输入验证码错误：\n");
		return;
	}

	if (strcmp(captcha, "czu111") != 0)
	{
		printf("验证码错误！注册失败！\n");
		return;
	}

	//保存用户信息到文件
	FILE* file = fopen("users.txt", "ab");  // 以追加模式打开文件
	if (file == NULL)
	{
		printf("用户信息文件打开失败\n");
		return;
	}
	User tmpUser;
	memcpy(tmpUser.username, username, sizeof(username));
	memcpy(tmpUser.password, password, sizeof(password));

	fwrite(&tmpUser, sizeof(User), 1, file);

	// fprintf(file, "%s %s\n", username, password);
	fclose(file);

	//更新用户数组
	strcpy(users[numUsers].username, username);
	strcpy(users[numUsers].password, password);
	numUsers++;

	printf("用户注册成功！\n");
	printf("======================================\n");
	printf("是否需要立即登录（1/0）: ");
	int answer;
	result = scanf("%d", &answer);
	if (result != 1)
	{
		printf("输入失败！\n");
		return;
	}

	while (answer != 1 && answer != 0)
	{
		printf("输入内容不符合要求！请重新输入（1/0）: ");
		result = scanf("%d", &answer);
		if (result != 1)
		{
			printf("输入失败！\n");
			return;
		}
	}

	if (answer == 1)
	{
		loginUser();
	}
	else
	{
		return;
	}
}

//用户登录
int loginUser()
{
	int choice;
	int result;
	printf("==============<用户登录>==============\n");
	printf("            1. 管理员登录\n");
	printf("            2. 学生登录\n");
	printf("            3. 返回上一级\n");
	printf("======================================\n");
	printf("请输入你的选择： ");
	result = scanf("%d", &choice);
	if (result != 1)
	{
		printf("输入选择失败！\n");
		return 1;
	}

	switch (choice) {
	case 1:
		adminLogin();
		break;
	case 2:
		studentLogin();
		break;
	case 3:
		mainMenu();
		return 1;
	default:
		printf("无效选项！请再次尝试！\n");
		return 1;
	}
	return 0;
}

//管理员菜单
void adminMenu()
{
	int choice;
	int result;

	do {
		printf("=============<管理员页面>=============\n");
		printf("            1. 课程信息\n");
		printf("            2. 学生信息\n");
		printf("            3. 选课信息\n");
		printf("            4. 退出\n");
		printf("======================================\n");
		printf("请输入你的选择：");
		result = scanf("%d", &choice);
		if (result != 1)
		{
			printf("输入选项失败！\n");
		}

		switch (choice) {
		case 1:
			courseInfoMenu();
			break;
		case 2:
			studentInfoMenu();
			break;
		case 3:
			enrollmentMenu();
			break;
		case 4:
			printf("退出管理员系统！\n");
			break;
		default:
			printf("无效选择！请再次尝试！\n");
		}
	} while (choice != 4);
}

//学生菜单
void studentMenu()
{
	int result, choice;
	printf("==============<学生页面>==============\n");
	printf("            1.进行选课\n");
	printf("            2.退选课程\n");
	printf("            3.查询个人信息\n");
	printf("            4.返回登录页面\n");
	printf("======================================\n");
	printf("请输入您的选择： ");
	result = scanf("%d", &choice);
	int hasAvailableCourses = 0; // 标志变量，用于判断是否有可选课程

	switch (choice)
	{
	case 1:
		enrollCourse();
		break;
	case 2:
		dropCourse();
		break;
	case 3:
		displayOneself();
		break;
	case 4:
		printf("返回登录页面\n");
		loginUser();
		break;
	default:
		printf("无效选项！请重新输入！\n");
		break;
	}
}

//保存课程信息到文件
int saveCoursesToFile()
{
	int numCourses = loadNumCoursesFromFile();

	//改为二进制
	FILE* file = fopen("courses.txt", "wb");
	if (file == NULL)
	{
		printf("无法打开 courses.txt 文件进行写入。\n");
		return 0;
	}

	for (int i = 0; i < numCourses; i++)
	{
		fwrite((courses + i), sizeof(Course), 1, file);
	}

	// FILE* file = fopen("courses.txt", "w");
	// if (file == NULL)
	// {
	// 	printf("无法打开 courses.txt 文件进行写入。\n");
	// 	return 0;
	// }

	// for (int i = 0; i < numCourses; i++)
	// {
	// 	fprintf(file, "%s,%d,%d,%s\n", courses[i].name, courses[i].hours, courses[i].credits, courses[i].major);
	// }

	fclose(file);
	return 1;
}

//保存学生信息到文件
int saveStudentsToFile()
{
	int numStudents = loadNumStudentsFromFile();

	//改为二进制
	FILE* file = fopen("students.txt", "wb");
	if (file == NULL)
	{
		printf("无法打开 students.txt 文件进行写入。\n");
		return 0;
	}

	for (int i = 0; i < numStudents; i++)
	{
		fwrite((students + i), sizeof(Student), 1, file);
	}

	// FILE* file = fopen("students.txt", "w");
	// if (file == NULL)
	// {
	// 	printf("无法打开 students.txt 文件进行写入。\n");
	// 	return 0;
	// }
	// Student a;
	// for (int i = 0; i < numStudents; i++)
	// {
	// 	fprintf(file, "%d,%s,%s,", students[i].id, students[i].name, students[i].major);

	// 	if (students[i].numCourses > 0)
	// 	{
	// 		fprintf(file, "%d,", students[i].numCourses);
	// 		for (int j = 0; j < students[i].numCourses; j++)
	// 		{
	// 			fprintf(file, "%s", students[i].courses[j]);
	// 			if (j < students[i].numCourses - 1)
	// 			{
	// 				fprintf(file, ",");
	// 			}
	// 		}
	// 	}
	// 	else
	// 	{
	// 		fprintf(file, "0");
	// 	}

	// 	fprintf(file, "\n");
	// }

	fclose(file);
	return 1;
}

//保存课程总数信息到文件
void saveNumCoursesToFile(int numCourses)
{
	FILE* file = fopen("num_courses.txt", "wb");
	if (file == NULL)
	{
		// 文件打开失败，无法保存课程总数
		printf("保存课程总数失败！\n");
		return;
	}

	fwrite(&numCourses, sizeof(int), 1, file);

	// fprintf(file, "%d", numCourses);
	fclose(file);
}

//保存学生总数信息到文件
void saveNumStudentsToFile(int numStudents)
{
	FILE* file = fopen("num_students.txt", "wb");
	if (file == NULL)
	{
		// 文件打开失败，无法保存课程总数
		printf("保存课程总数失败！\n");
		return;
	}

	fwrite(&numStudents, sizeof(int), 1, file);
	// fprintf(file, "%d", numStudents);
	fclose(file);
}

//管理员登录
void adminLogin()
{
	char username[max_length], password[max_length];
	int attempts = 0;
	int result;

	while (attempts < 5)
	{
		printf("=============<管理员登录>=============\n");
		printf("请输入用户名: ");
		result = scanf("%s", username);
		username[max_length - 1] = '\0';
		if (result != 1)
		{
			printf("用户名输入错误！\n");
			return;
		}

		printf("请输入密码：");
		result = scanf("%s", password);
		password[max_length - 1] = '\0';
		if (result != 1)
		{
			printf("密码输入错误！\n");
			return;
		}

		// 验证用户名和密码是否正确
		if (strcmp(username, "admin") == 0 && strcmp(password, "czu123") == 0)
		{
			printf("管理员登录成功！\n");
			printf("======================================\n");
			adminMenu(); // 进入管理员菜单
			return;
		}
		else
		{
			printf("用户名或密码错误！请再次尝试！\n");
			attempts++;
		}
	}

	printf("登录失败！尝试达到最大次数！您将强制退出系统！\n");
	exit(0); // 强行退出系统
}

//学生登录
void studentLogin()
{
	char username[max_length], password[max_length];
	int loginAttempts = 0;
	int loggedIn = 0;
	int result;
	int userIndex = -1;

	while (loginAttempts < 5 && !loggedIn)
	{
		printf("请输入用户名（用户名为学生学号）：");
		result = scanf("%s", username);
		username[max_length - 1] = '\0';
		if (result != 1)
		{
			printf("输入用户名错误！\n");
			return;
		}

		printf("请输入密码：");
		result = scanf("%s", password);
		password[max_length - 1] = '\0';
		if (result != 1)
		{
			printf("输入密码错误！\n");
			return;
		}

		// 检查用户名和密码是否正确
		for (int i = 0; i < numUsers; i++)
		{
			if (strcmp(users[i].username, username) == 0)
			{
				if (strcmp(users[i].password, password) == 0)
				{
					loggedIn = 1;
					userIndex = i;
				}
				else
				{
					loggedIn = 0; // 密码不匹配
				}
				break;
			}
		}

		if (!loggedIn)
		{
			loginAttempts++;
			if (loginAttempts == 5)
			{
				printf("已达到最大尝试次数！即将强制退出系统！\n");
				exit(0);
			}
			else
			{
				printf("用户名或密码错误！\n");
				printf("是否选择忘记密码(1/0): ");
				int choice;
				result = scanf("%d", &choice);
				if (result != 1)
				{
					printf("输入选项错误！\n");
					return;
				}

				if (choice == 1)
				{
					resetPassword(username);
					printf("密码已重置，请使用新密码进行登录！\n");
				}
			}
		}
	}

	if (loggedIn)
	{
		printf("登录成功！\n");
		studentMenu();
	}
}

//课程信息页面
void courseInfoMenu()
{
	int choice;
	int result;

	do {
		printf("==============<课程信息>==============\n");
		printf("            1. 添加课程\n");
		printf("            2. 删除课程\n");
		printf("            3. 更新课程\n");
		printf("            4. 查询课程\n");
		printf("            5. 返回管理员页面\n");
		printf("======================================\n");
		printf("请输入你的选择： ");
		result = scanf("%d", &choice);
		if (result != 1)
		{
			printf("输入选择失败！\n");
			return;
		}

		switch (choice)
		{
		case 1:
			addCourse();
			break;
		case 2:
			deleteCourse();
			break;
		case 3:
			updateCourse();
			break;
		case 4:
			queryCourses();
			break;
		case 5:
			printf("即将返回管理员页面！\n");
			break;
		default:
			printf("无效选项！请再次尝试！\n");
		}
	} while (choice != 5);
}

//学生信息页面
void studentInfoMenu()
{
	int choice;
	int result;

	do {
		printf("==============<学生信息>==============\n");
		printf("            1. 添加学生\n");
		printf("            2. 删除学生\n");
		printf("            3. 更新学生\n");
		printf("            4. 查询学生\n");
		printf("            5. 返回管理员页面\n");
		printf("======================================\n");
		printf("请输入你的选择： ");
		result = scanf("%d", &choice);
		if (result != 1)
		{
			printf("输入选择失败！\n");
			return;
		}

		switch (choice)
		{
		case 1:
			addStudent();
			break;
		case 2:
			deleteStudent();
			break;
		case 3:
			updateStudent();
			break;
		case 4:
			queryStudent();
			break;
		case 5:
			printf("即将返回管理员页面！\n");
			break;
		default:
			printf("无效选项！请再次尝试！\n");
		}
	} while (choice != 5);
}

//选课信息页面
void enrollmentMenu()
{
	int numStudents = loadNumStudentsFromFile();
	char courseName[max_length];
	int result;
	printf("请输入课程名称： ");
	result = scanf("%s", courseName);
	courseName[max_length - 1] = '\0';
	if (result != 1)
	{
		printf("输入课程名称失败！\n");
		return;
	}

	int numStudentsEnrolled = 0;

	printf("选修课程信息：%s\n", courseName);

	for (int i = 0; i < numStudents; i++)
	{
		for (int j = 0; j < students[i].numCourses; j++)
		{
			if (strcmp(students[i].courses[j], courseName) == 0)
			{
				printf("学号：%d    ", students[i].id);
				printf("姓名：%s    ", students[i].name);
				printf("专业：%s    \n", students[i].major);
				numStudentsEnrolled++;
				break;
			}
		}
	}

	printf("======================================\n");
	printf("选修课程人数：%d\n", numStudentsEnrolled);
	printf("======================================\n");

	// 询问是否继续查询选课信息
	int answer;
	printf("是否继续查询选课信息(1/0): ");
	result = scanf(" %d", &answer);
	if (result != 1)
	{
		printf("输入失败！\n");
		return;
	}

	if (answer == 1)
	{
		int c;
		while ((c = getchar()) != '\n' && c != EOF) {}

		enrollmentMenu(); // 递归调用继续查询选课信息
	}
	else
	{
		printf("返回管理员页面\n");
		return;
	}
}

//增加课程
void addCourse()
{
	int numCourses = loadNumCoursesFromFile();
	if (numCourses == max_courses)
	{
		printf("已达到最大课程数\n");
		return;
	}

	int result;
	Course newCourse;

	printf("请输入课程名称: ");
	result = scanf("%s", newCourse.name);
	if (result != 1)
	{
		printf("输入课程名称失败！\n");
		return;
	}

	// 检查课程名称是否已存在
	for (int i = 0; i < numCourses; i++)
	{
		if (strcmp(courses[i].name, newCourse.name) == 0)
		{
			printf("课程名称已存在，请选择操作：\n");
			printf("1. 返回页面\n");
			printf("2. 重新添加\n");
			printf("请选择操作（1/2）: ");

			int choice;
			result = scanf("%d", &choice);
			if (result != 1)
			{
				printf("输入选项失败！\n");
				return;
			}

			if (choice == 1)
			{
				printf("即将返回页面\n");
				return;
			}
			else if (choice == 2)
			{
				addCourse(); // 继续重新增加课程
			}
			else
			{
				printf("无效的选择。\n");
				return;
			}
		}
	}

	printf("请输入课程课时：");
	result = scanf("%d", &newCourse.hours);
	if (result != 1)
	{
		printf("输入课程课时失败！\n");
		return;
	}

	printf("请输入课程学分：");
	result = scanf("%d", &newCourse.credits);
	if (result != 1)
	{
		printf("输入课程学分失败！\n");
		return;
	}

	printf("请输入课程所属专业：");
	result = scanf("%s", newCourse.major);
	if (result != 1)
	{
		printf("输入课程所属专业失败！\n");
		return;
	}

	courses[numCourses] = newCourse;
	printf("课程信息成功导入！\n");
	//保存课程信息到文件
	saveCoursesToFile();
	numCourses++;
	saveNumCoursesToFile(numCourses);

	// 询问是否继续添加课程信息
	int answer;
	printf("是否继续添加 (1/0): ");
	result = scanf(" %d", &answer);
	if (result != 1)
	{
		printf("输入失败！\n");
		return;
	}

	int c;
	while ((c = getchar()) != '\n' && c != EOF) {}

	if (answer == 1)
	{
		addCourse(); // 递归调用继续添加课程
	}
	else
	{
		printf("返回管理员页面\n");
		return;
	}
}

//删除课程
void deleteCourse()
{
	int numCourses = loadNumCoursesFromFile();
	char courseName[max_length];
	int found = 0;
	int result;

	printf("请输入课程名称： ");
	result = scanf("%s", courseName);
	courseName[max_length - 1] = '\0';
	if (result != 1)
	{
		printf("输入课程名称失败！\n");
		return;
	}

	// 搜索课程并进行删除
	for (int i = 0; i < numCourses; i++)
	{
		if (strcmp(courses[i].name, courseName) == 0) {
			found = 1;
			printf("课程信息：\n");
			displayCourse(courses[i]);

			// 询问是否删除课程
			printf("是否删除该课程信息 (1/0): ");
			int choice;
			result = scanf("%d", &choice);
			if (result != 1)
			{
				printf("输入失败！\n");
				return;
			}

			if (choice == 1)
			{
				// 删除课程
				for (int j = i; j < numCourses - 1; j++)
				{
					courses[j] = courses[j + 1];
				}
				numCourses--;
				saveNumCoursesToFile(numCourses);
				printf("课程删除成功！\n");
				saveCoursesToFile();
				return;
			}
			else
			{
				printf("已取消删除！\n");
				return;
			}
		}
	}

	if (!found)
	{
		printf("未查询到该课程信息\n");
	}

	// 询问是否继续添加课程信息
	int answer;
	printf("是否继续删除 (1/0): ");
	result = scanf(" %d", &answer);
	if (result != 1)
	{
		printf("输入失败！\n");
		return;
	}

	if (answer == 1)
	{
		int c;
		while ((c = getchar()) != '\n' && c != EOF) {}

		deleteCourse(); // 递归调用继续删除课程
	}
	else
	{
		printf("返回管理员页面\n");
		return;
	}
}

//更新课程
void updateCourse()
{
	int numCourses = loadNumCoursesFromFile();
	char courseName[max_length];
	int found = 0;
	int result;

	printf("请输入要更新的课程名称：");
	result = scanf("%s", courseName);
	courseName[max_length - 1] = '\0';
	if (result != 1)
	{
		printf("输入课程名称失败！\n");
		return;
	}

	// 搜索课程并进行更新
	for (int i = 0; i < numCourses; i++)
	{

		if (strcmp(courses[i].name, courseName) == 0)
		{
			found = 1;
			printf("当前课程信息：\n");
			displayCourse(courses[i]);

			// 输入新的课程信息
			printf("请输入新的课程学时：");
			result = scanf("%d", &courses[i].hours);
			if (result != 1)
			{
				printf("输入课程学时失败！\n");
				return;
			}

			printf("请输入新的课程学分：");
			result = scanf("%d", &courses[i].credits);
			if (result != 1)
			{
				printf("输入课程学分失败！\n");
				return;
			}

			printf("请输入新的课程专业：");
			result = scanf("%s", courses[i].major);
			if (result != 1)
			{
				printf("输入课程专业失败！\n");
				return;
			}

			printf("课程信息更新成功！\n");
			saveCoursesToFile();
		}
	}

	if (!found)
	{
		printf("未查询到该课程信息\n");
	}

	// 询问是否继续更新课程信息
	int answer;
	printf("是否继续更新 (1/0): ");
	result = scanf(" %d", &answer);
	if (result != 1)
	{
		printf("输入失败！\n");
		return;
	}

	if (answer == 1)
	{
		int c;
		while ((c = getchar()) != '\n' && c != EOF) {}

		updateCourse(); // 递归调用继续更新课程
	}
	else
	{
		printf("返回管理员页面\n");
		return;
	}
}

//查询课程
void queryCourses()
{
	int choice;
	int result;
	printf("==============<课程查询>==============\n");
	printf("            1. 单个查询\n");
	printf("            2. 所有查询\n");
	printf("            3. 按专业查询\n");
	printf("            4. 返回上一级\n");
	printf("======================================\n");
	printf("请输入选项：");
	result = scanf("%d", &choice);
	if (result != 1)
	{
		printf("输入选项失败！\n");
		return;
	}

	switch (choice)
	{
	case 1:
		querySingleCourse();
		break;
	case 2:
		queryAllCourses();
		break;
	case 3:
		queryCourseByMajor();
		break;
	case 4:
		printf("即将返回上一页\n");
		break;
	default:
		printf("无效的选项，请重新输入。\n");
		break;
	}
}

//增加学生
void addStudent()
{
	int numStudents = loadNumStudentsFromFile();
	if (numStudents == max_students)
	{
		printf("已达到最大学生数\n");
		return;
	}

	int result;
	Student newStudent;

	printf("请输入学生学号: ");
	result = scanf("%d", &newStudent.id);
	if (result != 1)
	{
		printf("输入学生学号失败！\n");
		studentInfoMenu();
	}

	// 检查课程名称是否已存在
	for (int i = 0; i < numStudents; i++)
	{
		if (students[i].id == newStudent.id)
		{
			printf("学生学号已存在，请选择操作：\n");
			printf("1. 返回页面\n");
			printf("2. 重新添加\n");
			printf("请选择操作（1/2）: ");

			int choice;
			result = scanf("%d", &choice);
			if (result != 1)
			{
				printf("输入选项失败！\n");
				return;
			}

			if (choice == 1)
			{
				printf("即将返回页面\n");
				return;
			}
			else if (choice == 2)
			{
				addStudent(); // 继续添加课程
			}
			else
			{
				printf("无效的选择。\n");
				return;
			}
		}
	}

	printf("请输入学生姓名：");
	result = scanf("%s", &newStudent.name);
	if (result != 1)
	{
		printf("输入学生姓名失败！\n");
		return;
	}

	printf("请输入学生专业：");
	result = scanf("%s", &newStudent.major);
	if (result != 1)
	{
		printf("输入学生专业失败！\n");
		return;
	}

	students[numStudents] = newStudent;
	printf("学生信息成功导入！\n");
	//保存学生信息到文件
	saveStudentsToFile();
	numStudents++;
	saveNumStudentsToFile(numStudents);

	// 询问是否继续添加学生信息
	int answer;
	printf("是否继续添加 (1/0): ");
	result = scanf(" %d", &answer);
	if (result != 1)
	{
		printf("输入失败！\n");
		return;
	}

	if (answer == 1)
	{
		int c;
		while ((c = getchar()) != '\n' && c != EOF) {}

		addStudent(); // 递归调用继续添加学生
	}
	else
	{
		printf("返回管理员页面\n");
		return;
	}
}

//删除学生
void deleteStudent()
{
	int numStudents = loadNumStudentsFromFile();
	int studentId;
	int found = 0;
	int result;

	printf("请输入学生学号：");
	result = scanf("%d", &studentId);
	if (result != 1)
	{
		printf("输入学生学号失败！\n");
		return;
	}

	// 搜索学生并进行删除
	for (int i = 0; i < numStudents; i++)
	{
		if (students[i].id == studentId)
		{
			found = 1;
			printf("学生信息：\n");
			displayStudent(students[i]);

			// 询问是否删除学生
			printf("是否删除该学生信息 (1/0): ");
			int choice;
			result = scanf("%d", &choice);
			if (result != 1)
			{
				printf("输入失败！\n");
				return;
			}

			if (choice == 1)
			{
				// 删除学生
				for (int j = i; j < numStudents - 1; j++)
				{
					students[j] = students[j + 1];
				}
				numStudents--;
				saveNumStudentsToFile(numStudents);
				printf("学生删除成功！\n");
				saveStudentsToFile();
				return;
			}
			else {
				printf("已取消删除！\n");
				return;
			}
		}
	}

	if (!found)
	{
		printf("未查询到该学生信息\n");
	}

	// 询问是否继续添加学生信息
	int answer;
	printf("是否继续删除 (1/0): ");
	result = scanf(" %d", &answer);
	if (result != 1)
	{
		printf("输入失败！\n");
		return;
	}

	if (answer == 1)
	{
		int c;
		while ((c = getchar()) != '\n' && c != EOF) {}

		deleteStudent(); // 递归调用继续删除学生
	}
	else
	{
		printf("返回管理员页面\n");
		return;
	}
}

//更新学生
void updateStudent()
{
	int numStudents = loadNumStudentsFromFile();
	int studentId;
	int found = 0;
	int result;

	printf("请输入要更新的学生学号： ");
	result = scanf("%d", &studentId);
	if (result != 1)
	{
		printf("输入学生学号失败！\n");
		return;
	}

	// 搜索学生并进行更新
	for (int i = 0; i < numStudents; i++)
	{
		if (students[i].id == studentId)
		{
			found = 1;
			printf("当前学生信息：\n");
			displayStudent(students[i]);

			// 输入新的学生信息
			printf("请输入新的学生姓名：");
			result = scanf("%s", students[i].name);
			if (result != 1)
			{
				printf("输入学生姓名失败！\n");
				return;
			}

			printf("请输入新的学生专业：");
			result = scanf("%s", students[i].major);
			if (result != 1)
			{
				printf("输入学生专业失败！\n");
				return;
			}

			printf("学生信息更新成功！\n");
			saveStudentsToFile();
		}
	}

	if (!found)
	{
		printf("未查询到该学生信息!\n");
	}

	// 询问是否继续更新学生信息信息
	int answer;
	printf("是否继续更新 (1/0): ");
	result = scanf(" %d", &answer);
	if (result != 1)
	{
		printf("输入失败！\n");
		return;
	}

	int c;
	while ((c = getchar()) != '\n' && c != EOF) {}

	if (answer == 1)
	{
		updateStudent(); // 递归调用继续更新学生
	}
	else
	{
		printf("返回管理员页面\n");
		return;
	}
}

//查询学生
void queryStudent()
{
	int choice;
	int result;
	printf("==============<学生查询>==============\n");
	printf("            1. 单个查询\n");
	printf("            2. 所有查询\n");
	printf("            3. 按专业查询\n");
	printf("            4. 返回上一级\n");
	printf("======================================\n");
	printf("请输入选项：");
	result = scanf("%d", &choice);
	if (result != 1)
	{
		printf("输入选项失败！\n");
		return;
	}

	switch (choice)
	{
	case 1:
		querySingleStudent();
		break;
	case 2:
		queryAllStudents();
		break;
	case 3:
		queryStudentByMajor();
		break;
	case 4:
		printf("即将返回上一页\n");
		break;
	default:
		printf("无效的选项，请重新输入。\n");
		break;
	}
}

//展示课程信息
void displayCourse(Course course)
{
	printf("名称： %s\n", course.name);
	printf("学时： %d\n", course.hours);
	printf("专业： %s\n", course.major);
	printf("学分： %d\n", course.credits);
	printf("======================================\n");
}

//查询单个课程信息
void querySingleCourse()
{
	int numCourses = loadNumCoursesFromFile();
	char courseName[max_length];
	int result;
	printf("请输入课程名称：");
	result = scanf("%s", courseName);
	courseName[max_length - 1] = '\0';
	if (result != 1)
	{
		printf("输入课程名称失败！\n");
		return;
	}

	int found = 0;
	for (int i = 0; i < numCourses; i++)
	{
		if (strcmp(courses[i].name, courseName) == 0)
		{
			found = 1;
			printf("课程信息：\n");
			displayCourse(courses[i]);
			break;
		}
	}

	if (!found)
	{
		printf("未找到该课程。\n");
	}

	// 询问是否继续查询单个课程信息
	int answer;
	printf("是否继续查询单个课程信息 (1/0): ");
	result = scanf(" %d", &answer);
	if (result != 1)
	{
		printf("输入失败！\n");
		return;
	}

	int c;
	while ((c = getchar()) != '\n' && c != EOF) {}

	if (answer == 1)
	{
		querySingleCourse(); // 递归调用继续查询单个课程信息
	}
	else
	{
		printf("返回查询页面\n");
		queryCourses();
	}
}

//查询所有课程信息
void queryAllCourses()
{
	int numCourses = loadNumCoursesFromFile();
	if (numCourses == 0) {
		printf("当前没有课程信息。\n");
		return;
	}

	printf("所有课程信息：\n");
	for (int i = 0; i < numCourses; i++) {
		printf("课程 %d:\n", i + 1);
		displayCourse(courses[i]);
	}
}

//按照专业查询课程信息
void queryCourseByMajor()
{
	int numCourses = loadNumCoursesFromFile();
	char major[max_length];
	int result;
	printf("请输入专业名称：");
	result = scanf("%s", major);
	major[max_length - 1] = '\0';
	if (result != 1)
	{
		printf("输入专业名称失败！\n");
		return;
	}

	int found = 0;
	printf("专业: %s \n", major);
	for (int i = 0; i < numCourses; i++)
	{
		if (strcmp(courses[i].major, major) == 0)
		{
			found = 1;
			printf("课程 :\n");
			displayCourse(courses[i]);
		}
	}

	if (!found) {
		printf("未找到该专业的课程。\n");
	}

	// 询问是否继续按照专业查询课程信息
	int answer;
	printf("是否继续按照专业查询课程信息 (1/0): ");
	result = scanf(" %d", &answer);
	if (result != 1)
	{
		printf("输入失败！\n");
		return;
	}

	if (answer == 1)
	{
		int c;
		while ((c = getchar()) != '\n' && c != EOF) {}

		queryCourseByMajor(); // 递归调用继续按照专业查询个人信息
	}
	else
	{
		printf("返回查询页面\n");
		return;
	}
}

//显示学生信息
void displayStudent(Student student)
{
	printf("学号： %d\n", student.id);
	printf("姓名： %s\n", student.name);
	printf("专业： %s\n", student.major);
	printf("选课：");

	if (student.numCourses > 0) 
	{
		for (int i = 0; i < student.numCourses; i++)
		{
			if (strlen(student.courses[i]) > 0)
			{
				printf(" %s", student.courses[i]);
			}
		}
		printf("\n");
		printf("选课总数： %d\n", student.numCourses);
	}
	else {
		printf("暂无选课\n");
		printf("选课总数： 0\n");
	}
	printf("======================================\n");
}

//查询单个学生信息
void querySingleStudent()
{
	int numStudents = loadNumStudentsFromFile();
	int studentId;
	int result;
	printf("请输入学生学号：");
	result = scanf("%d", &studentId);
	if (result != 1)
	{
		printf("输入学生学号失败！\n");
		return;
	}

	int found = 0;
	for (int i = 0; i < numStudents; i++)
	{
		if (students[i].id == studentId)
		{
			found = 1;
			printf("学生信息：\n");
			displayStudent(students[i]);
			break;
		}
	}

	if (!found)
	{
		printf("未找到该学生。\n");
	}

	// 询问是否继续查询单个学生信息
	int answer;
	printf("是否继续查询单个学生信息 (1/0): ");
	result = scanf(" %d", &answer);
	if (result != 1)
	{
		printf("输入失败！\n");
		return;
	}

	if (answer == 1)
	{
		int c;
		while ((c = getchar()) != '\n' && c != EOF) {}

		querySingleStudent(); // 递归调用继续查询单个学生信息
	}
	else
	{
		printf("返回查询页面\n");
		queryStudent();
	}
}

//查询所有学生信息
void queryAllStudents()
{
	int numStudents = loadNumStudentsFromFile();
	if (numStudents == 0)
	{
		printf("当前没有学生信息。\n");
		return;
	}

	printf("所有学生信息：\n");
	for (int i = 0; i < numStudents; i++)
	{
		displayStudent(students[i]);
	}
}

//按照专业查询学生信息
void queryStudentByMajor()
{
	int numStudents = loadNumStudentsFromFile();
	char major[max_length];
	int result;
	printf("请输入专业名称：");
	result = scanf("%s", major);
	major[max_length - 1] = '\0';
	if (result != 1)
	{
		printf("输入专业名称失败！\n");
		return;
	}

	int found = 0;
	printf("专业为 %s 的课程信息：\n", major);
	for (int i = 0; i < numStudents; i++) {
		if (strcmp(students[i].major, major) == 0)
		{
			found = 1;
			displayStudent(students[i]);
		}
	}

	if (!found)
	{
		printf("未找到该专业的学生。\n");
	}

	// 询问是否继续按照专业查询学生信息
	int answer;
	printf("是否继续按照专业查询学生信息 (1/0): ");
	result = scanf(" %d", &answer);
	if (result != 1)
	{
		printf("输入失败！\n");
		return;
	}

	if (answer == 1)
	{
		int c;
		while ((c = getchar()) != '\n' && c != EOF) {}

		queryStudentByMajor(); // 递归调用继续按照专业查询个人信息
	}
	else
	{
		printf("返回查询页面\n");
		queryStudent();
	}
}

// 替换密码
void resetPassword(const char* username)
{
	FILE* file = fopen("users.bin", "r");
	if (file == NULL)
	{
		printf("打开文件失败！\n");
		return;
	}

	FILE* tempFile = fopen("temp.txt", "w");
	if (tempFile == NULL)
	{
		printf("创建临时文件失败！\n");
		fclose(file);
		return;
	}

	char buffer[max_length];
	int found = 0;
	int result;

	// 逐行读取文件并查找用户名
	while (fgets(buffer, sizeof(buffer), file))
	{
		char fileUsername[max_length];
		fileUsername[max_length - 1] = '\0';
		char filePassword[max_length];
		filePassword[max_length - 1] = '\0';

		// 从文件中读取用户名和密码
		result = sscanf(buffer, "%s %s", fileUsername, filePassword);
		if (result != 2)
		{
			break;  // 文件中没有更多信息可读，退出循环
		}

		// 检查用户名是否匹配
		if (strcmp(fileUsername, username) == 0)
		{
			found = 1;
			char newPassword[max_length];
			printf("输入新密码：");
			result = scanf("%s", newPassword);
			newPassword[max_length - 1] = '\0';
			if (result != 1)
			{
				printf("输入密码错误！\n");
				fclose(file);
				fclose(tempFile);
				remove("temp.txt");
				return;
			}

			// 将新密码写入临时文件
			fprintf(tempFile, "%s %s\n", fileUsername, newPassword);
			printf("密码替换成功！\n");

			// 更新users数组中对应用户的密码
			for (int i = 0; i < numUsers; i++)
			{
				if (strcmp(users[i].username, username) == 0)
				{
					strcpy(users[i].password, newPassword);
					break;
				}
			}
		}
		else
		{
			// 将原用户名和密码写入临时文件
			fprintf(tempFile, "%s %s\n", fileUsername, filePassword);
		}
	}

	if (!found)
	{
		printf("该用户未找到！\n");

		printf("是否进行新用户的注册？(1/0)\n");
		int choice;
		result = scanf("%d", &choice);
		if (result != 1)
		{
			printf("输入选项失败！\n");
			fclose(file);
			fclose(tempFile);
			remove("temp.txt");
			return;
		}

		if (choice == 1)
		{
			int c;
			while ((c = getchar()) != '\n' && c != EOF) {}
			registerUser();
		}
		else if (choice == 0)
		{
			studentLogin();
		}
		else
		{
			printf("无效选项！请重新尝试！\n");
			fclose(file);
			fclose(tempFile);
			remove("temp.txt");
			return;
		}
	}

	// 将原文件中剩余的账户信息写入临时文件
	while (fgets(buffer, sizeof(buffer), file))
	{
		fprintf(tempFile, "%s", buffer);
	}

	fclose(file);
	fclose(tempFile);

	// 删除原文件并重命名临时文件为原文件名
	remove("users.txt");
	result = rename("temp.txt", "users.txt");
}

//进行选课
void enrollCourse()
{
	int hasAvailableCourses = 0;
	int result, studentId;
	int studentIndex = 0;
	int numCourses = loadNumCoursesFromFile();
	int numStudents = loadNumStudentsFromFile();

	printf("请输入你的学号：");
	result = scanf("%d", &studentId);
	if (result != 1)
	{
		printf("输入学号错误！\n");
		return;
	}
	for (int i = 0; i < numStudents; i++)
	{
		if (students[i].id == studentId)
		{
			studentIndex = i;
			break;
		}
	}
	// 遍历课程信息，显示与学生专业相同的课程
	printf("可选课程：\n");
	for (int i = 0; i < numCourses; i++)
	{
		// 判断课程专业是否与学生专业相同
		if (strcmp(courses[i].major, students[studentIndex].major) == 0)
		{
			printf("课程名称：%s\n", courses[i].name);
			printf("所属专业：%s\n", courses[i].major);
			printf("已选人数：%d\n", courses[i].numStudents > 0 ? courses[i].numStudents : 0);
			printf("======================================\n");
			printf("\n");
			hasAvailableCourses = 1; // 设置标志变量为1，表示存在可选课程
		}
	}

	if (!hasAvailableCourses)
	{
		printf("暂无可选课程。\n");
		studentMenu();
		return;
	}

	// 提示学生进行选课
	printf("请选择要选修的课程：");
	char courseName[max_length];
	result = scanf("%s", courseName);
	courseName[max_length - 1] = '\0';
	if (result != 1)
	{
		printf("输入课程名称错误！\n");
		studentMenu();
		return;
	}

	// 查找选修的课程
	int selectedCourseIndex = -1;
	for (int i = 0; i < numCourses; i++)
	{
		// 判断课程名称和专业是否与学生选择相符合
		if (strcmp(courses[i].name, courseName) == 0 && strcmp(courses[i].major, students[studentIndex].major) == 0)
		{
			selectedCourseIndex = i;
			break;
		}
	}

	if (selectedCourseIndex == -1)
	{
		printf("选择的课程不存在或不属于您的专业！\n");
		return;
	}

	// 检查课程是否已被选修
	for (int i = 0; i < students[studentIndex].numCourses; i++)
	{
		if (strcmp(students[studentIndex].courses[i], courseName) == 0)
		{
			printf("您已选择该课程！\n");
			studentMenu();
			return;
		}
	}

	// 检查课程人数是否已满
	if (courses[selectedCourseIndex].numStudents >= 100)
	{
		printf("该课程人数已满，无法选修！\n");
		studentMenu();
		return;
	}

	// 检查选课数量是否超过最大值
	if (students[studentIndex].numCourses >= max_enroll_course)
	{
		printf("选课数量超过最大值！\n");
		studentMenu();
		return;
	}

	// 检查 numCourses 是否存在
	if (students[studentIndex].numCourses > 0)
	{
		// 检查课程数量是否超过预设的最大值
		if (students[studentIndex].numCourses >= 4)
		{
			printf("课程数量超过最大值！\n");
			studentMenu();
			return;
		}
	}
	else
	{
		// 设置默认的选课数量为 0
		students[studentIndex].numCourses = 0;
	}

	// 确认选课
	printf("确认选修课程 %s（1/0）: ", courseName);
	int choice;
	result = scanf("%d", &choice);
	if (result != 1)
	{
		printf("输入选项错误！\n");
		return;
	}

	if (choice == 1)
	{
		// 添加课程信息到学生选课列表中
		if (students[studentIndex].numCourses >= 0 && students[studentIndex].numCourses < max_enroll_course)
		{
			int courseIndex = students[studentIndex].numCourses;

			// 复制课程名称到选课列表
			strncpy(students[studentIndex].courses[courseIndex], courseName, max_length - 1);
			students[studentIndex].courses[courseIndex][max_length - 1] = '\0';

			// 更新选课数量
			students[studentIndex].numCourses++;
		}
		else
		{
			printf("无效的课程索引！\n");
			return;
		}

		printf("选课成功！\n");
		// 将选课信息存入文件
		saveCoursesToFile();
		saveStudentsToFile();
		studentMenu();
	}
	else if (choice == 0)
	{
		printf("取消选课！\n");
		// 保存空的选课信息到文件
		saveCoursesToFile();
		saveStudentsToFile();
		studentMenu();
	}
	else
	{
		printf("无效的选择。\n");
	}
}

//进行退选
void dropCourse()
{
	int result, studentId, choice;
	int studentIndex = 0;
	int numStudents = loadNumStudentsFromFile();
	int numCourses = loadNumCoursesFromFile();

	printf("请输入你的学号：");
	result = scanf("%d", &studentId);
	if (result != 1)
	{
		printf("输入学号错误！\n");
		return;
	}
	for (int i = 0; i < numStudents; i++)
	{
		if (students[i].id == studentId)
		{
			studentIndex = i;
			break;
		}
	}
	printf("已选课程列表：\n");
	for (int i = 0; i < students[studentIndex].numCourses; i++)
	{
		printf("%d. %s\n", i + 1, students[studentIndex].courses[i]);
	}

	printf("请输入要退选的课程编号：");
	result = scanf("%d", &choice);
	if (result != 1 || choice < 1 || choice > students[studentIndex].numCourses)
	{
		printf("无效的选择！\n");
		return;
	}

	// 退选课程
	char droppedCourse[max_length];
	strcpy(droppedCourse, students[studentIndex].courses[choice - 1]);

	for (int i = choice - 1; i < students[studentIndex].numCourses - 1; i++)
	{
		strcpy(students[studentIndex].courses[i], students[studentIndex].courses[i + 1]);
	}

	students[studentIndex].numCourses--;

	// 更新课程已选人数
	int courseIndex = -1; // 初始化课程索引为 -1，表示未找到

	for (int i = 0; i < numCourses; i++)
	{
		if (strcmp(courses[i].name, droppedCourse) == 0)
		{
			courseIndex = i; // 找到了匹配的课程，将索引赋值给 courseIndex
			break; // 找到后跳出循环
		}
	}

	if (courseIndex != -1)
	{
		courses[courseIndex].numStudents--;
	}

	printf("课程 %s 退选成功！\n", droppedCourse);
	// 将退选后的选课信息存入文件
	saveCoursesToFile();
	saveStudentsToFile();
	studentMenu();
}

//个人信息
void displayOneself()
{
	int result, studentId;
	int numStudents = loadNumStudentsFromFile();
	int numCourses = loadNumCoursesFromFile();
	int studentIndex = -1;
	printf("请输入你的学号：");
	result = scanf("%d", &studentId);
	if (result != 1)
	{
		printf("输入学号错误！\n");
		return;
	}
	for (int i = 0; i < numStudents; i++)
	{
		if (students[i].id == studentId)
		{
			studentIndex = i;
			break;
		}
	}

	if (studentIndex == -1)
	{
		printf("找不到对应的学生信息。\n");
		return;
	}

	displayStudent(students[studentIndex]);

	// 计算学生已修学分总数
	int totalCredits = 0;
	for (int i = 0; i < students[studentIndex].numCourses; i++)
	{
		// 在课程列表中查找已选课程的学分信息
		for (int j = 0; j < numCourses; j++)
		{
			if (strcmp(courses[j].name, students[studentIndex].courses[i]) == 0)
			{
				totalCredits += courses[j].credits;
				break;
			}
		}
	}
	printf("已修学分总数：%d\n", totalCredits);

	// 计算学生还需再修学分数
	int remainingCredits = requiredCredits - totalCredits;
	if (remainingCredits < 0)
	{
		remainingCredits = 0;
	}
	printf("还需修读学分数：%d\n", remainingCredits);
	studentMenu();
}