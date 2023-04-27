#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <ctime>
#include <cstdlib>

using namespace std;

// 定义银行账户类
class Account {
	private:
		string id;  // 身份标识号
		string name;  // 姓名
		string phone;  // 电话
		string email;  // 电子邮箱
		string idCard;  // 身份证号
		string cardNo;  // 银行卡号
		string password;//密码 
		double balance;  // 账户余额
		string status="正常";   //账户状态 

	public:
		// 构造函数
		Account(string id, string name, string phone, string email, string idCard, string cardNo) {
			this->id = id;
			this->name = name;
			this->phone = phone;
			this->email = email;
			this->idCard = idCard;
			this->cardNo = cardNo;
			this->balance = 0;
		}	

		// 获取账户信息
		string& getId() {
			return id;
		}

		string& getName() {
			return name;
		}

		string& getPhone() {
			return phone;
		}

		string& getEmail() {
			return email;
		}

		string& getIdCard() {
			return idCard;
		}

		string& getCardNo() {
			return cardNo;
		}
		
		//getPassword函数
		string& getPassword(){
			return password;
		}

		double& getBalance() {
			return balance;
		}
		
		//菜单显示函数
		void showMenu(){
			std::cout<<id<<"/n"<<name<<"/n"<<phone<<"/n"<<email<<"/n"<<idCard<<"/n"<<cardNo<<"/n"<<balance<<endl;
		} 
		
		//销户函数 
		void closeAccount() ;

		// 存款
		void deposit(double amount) {
			balance += amount;
			cout << "存款成功，当前账户余额为：" << balance << endl;
		}

		// 取款
		void withdraw(double amount) {
			if (amount <= balance) {
				balance -= amount;
				cout << "取款成功，当前账户余额为：" << balance << endl;
			} else {
				cout << "余额不足，无法取款。" << endl;
			}
		}
		
		//makeTransaction函数
		bool makeTransaction(double amount){
			return true;
		} 
		
		//isVIP函数
		bool isVIP(){
			if(setVIP()) return true;
			return false;
		}
		
		//setVIP函数
		bool setVIP(double balance=0,int VIP_THRESHOLD=100){
			if(balance>=VIP_THRESHOLD) return true;
			return false;
		} 

		// 将账户信息转为字符串形式
		string toString() {
			stringstream ss;
			ss << id << "," << name << "," << phone << "," << email << "," << idCard << "," << cardNo << "," << balance;
			return ss.str();
		}
};
void upgradeToVIP(Account& account) {
	//VIP_THRESHOLD未赋值，需要在Account类中添加 isVIP 和 setVIP 函数 
	int VIP_THRESHOLD=100; 
    if ( !account.isVIP()) {
    	double balance;
    	balance=account.getBalance();
        account.setVIP(balance,VIP_THRESHOLD);
        std::cout << "恭喜您已升级为VIP客户！" << endl;
    }
}

//需要在Account类中添加 makeTransaction函数 
// 在账户进行存款、取款、转账时调用该函数进行自动升级判断
void transactionWithUpgrade(Account& account, double amount) {
    account.makeTransaction(amount);
    upgradeToVIP(account);
}

// 在转账时检查账户是否是VIP客户，如果是则不收取手续费
bool isTransferFree(Account& account) {
    if (account.isVIP()) {
        std::cout << "您是VIP客户，转账免手续费！" << endl;
        return true;
    }
    return false;
}

// 定义银行账户管理类
class Bank {
	private:
		vector<Account> accounts;  // 账户列表

	public:
		void copyAccount(vector<Account>* &myAccounts){
			myAccounts = &accounts;
		}
		void loadAccountsFromFile();
		void saveAccountsToFile();
		// 构造函数
		Bank() {
			void loadAccountsFromFile();  // 从文件导入账户信息
		}

		// 析构函数
		~Bank() {
			void saveAccountsToFile();  // 将账户信息保存到文件
			// for (int i = 0; i < accounts.size(); i++) {
			// 	delete accounts[i];  // 释放账户内存
			// }
		}
};
// 从文件导入账户信息
void Bank::loadAccountsFromFile() {
	ifstream infile("accounts.txt");
	if (!infile.is_open()) {
		std::cout << "Error opening file." << endl;
		return;
	}

	string line;
	while (getline(infile, line)) {
		stringstream ss(line);
		string id, name, phone, email, idcard, card;
		double balance;
		getline(ss, id, ' ');
		getline(ss, name, ' ');
		getline(ss, phone, ' ');
		getline(ss, email, ' ');
		getline(ss, idcard, ' ');
		getline(ss, card, ' ');
		// ss >> balance;
		Account account=Account(id, name, phone, email, idcard, card);
		accounts.push_back(account);
	}

	infile.close();
}
// 修改账户信息
void modify_account(vector<Account> accounts) {
	string id;
	std::cout << "请输入要修改的账户ID：";
	cin >> id;
	for (auto &account : accounts) {
		if (account.getId() == id) {
			int choice;
			std::cout << "请选择要修改的信息：" << endl;
			std::cout << "1. 电话" << endl;
			std::cout << "2. 电子邮箱" << endl;
			cin >> choice;
			if (choice == 1) {
				string new_phone;
				std::cout << "请输入新的电话号码：";
				std::cin >> new_phone;
				account.getPhone() = new_phone;
				std::cout << "修改成功！" << endl;
			} else if (choice == 2) {
				string new_email;
				std::cout << "请输入新的电子邮箱：";
				cin >> new_email;
				account.getEmail() = new_email;
				std::cout << "修改成功！" << endl;
			} else {
				std::cout << "无效的选择！" << endl;
			}
			return;
		}
	}
	std::cout << "未找到对应账户！" << endl;
}

// 存储账户信息到文件
void Bank::saveAccountsToFile() {
	ofstream out_file("accounts.txt");
	if (!out_file) {
		cout << "文件打开失败！" << endl;
		return;
	}
	for (auto &account : accounts) {
		out_file << account.getId() << " " << account.getName() << " " << account.getPhone() << " "
		         << account.getEmail() << " " << account.getIdCard() << " " << account.getCardNo()
		         << " " << account.getBalance() << endl;
	}
	out_file.close();
	cout << "账户信息已成功保存到文件！" << endl;
}

//登录账户 
void login(vector<Account>& accounts) {
	cout << "请输入账号ID：";
	string id;
	cin >> id;

	// 在账户列表中查找账户
	for (auto& account : accounts) {
		if (account.getId() == id) {
			// 输入密码
			cout << "请输入密码：";
			string password;
			cin >> password;

			// 检查密码是否正确
			if (account.getPassword() == password) {
				cout << "登录成功！" << endl;
				// 显示账户信息菜单
				account.showMenu();
				return;
			} else {
				cout << "密码错误！" << endl;
				return;
			}
		}
	}

	// 没有找到对应的账户
	cout << "账号不存在！" << endl;
}
void printMenu() {
	cout << "欢迎来到银行账户管理系统!" << endl;
	cout << "1. 开户" << endl;
	cout << "2. 登录" << endl;
	cout << "3. 浏览账户" << endl;
	cout << "4. 查询账户" << endl;
	cout << "5. 取款和存款" << endl;
	cout << "请输入您的选择: ";
}

void createAccount(vector<Account>& accounts) {
	cout << "请输入您的姓名: ";
	string name;
	cin >> name;
	cout << "请输入您的ID: ";
	string id;
	cin >> id;
	cout << "请输入您的电话号码: ";
	string phone;
	cin >> phone;
	cout << "请输入您的邮箱: ";
	string email;
	cin >> email;
	cout << "请输入您的身份证号码: ";
	string idCard;
	cin >> idCard;
	int a;
	a=10000+(rand()%100);
	// cout << "账户创建成功，您的银行卡号是: " << a << endl;

	string cardNo = std::to_string(a);
	Account account(id,name,phone,email,idCard,cardNo);
	accounts.push_back(account); 
	cout << "账户创建成功，您的银行卡号是: " << account.getCardNo() << endl;
	//aaa
	// vector<Account> accountT;
	// accountT.push_back(account); 
	// cout << "账户创建成功，您的银行卡号是: " << account.getCardNo() << endl;
	// cout << "账户创建成功，您的银行卡号是: " << cardNo << endl;
	// delete account;
}

void test(){
	int a;
	a=10000+(rand()%100);
	string aa = std::to_string(a);
	// a=10000+(rand()%100);
	cout << "账户创建成功，您的银行卡号是: " << aa << endl;
}

int main() {
	vector<Account>* accounts;
	Bank bank;
	bank.copyAccount(accounts);
	bool quit = false;
	// test();
	while (!quit) {
		printMenu();
		char choice;
		cin >> choice;
		switch (choice) {
			case '1':
				createAccount(*accounts);
				break;
			case '2':
				login(*accounts);
				break;
			case '3':
				// browseAccounts(accounts);
				break;
			case '4':
				// searchAccount(accounts);
				break;
			case '5':
				bank.saveAccountsToFile();
				quit = true;
				break;
			default:
				cout << "无效选择，请再次输入" << endl;
		}
	}
	return 0;
}

void Account::closeAccount() {
	if (balance != 0) {
		cout << "不能办理销户，账户余额不为零！" << endl;
		return;
	}
	this->status = "已注销";
	cout << "销户成功！" << endl;
}
//转账 
void transfer(vector<Account>& accounts, const string& currentCardNo) {
	string targetCardNo;
	double amount;
	cout << "请输入您转账的目标卡号: ";
	cin >> targetCardNo;
	cout << "请输入您转账的金额: ";
	cin >> amount;

	for (auto& account : accounts) {
		if (account.getCardNo() == targetCardNo) {
			double transferFee = amount * 0.01;
			if (account.getBalance() >= amount + transferFee) {
				for (auto& currentAccount : accounts) {
					if (currentAccount.getCardNo() == currentCardNo) {
						//需要在Account类中添加两个新函数对余额进行运算，否则此处会多输出 存款成功，当前账户余额为： 
						currentAccount.withdraw(amount + transferFee);
						account.deposit(amount);
						cout << "转账成功!" << endl;
						return;   
					}
				}
			} else {
				cout << "转账失败，余额不足." << endl;
				return;
			}
		}
	}

	cout << "转账失败，目标卡号无效." << endl;
}
void viewAccounts(vector<Account>& accounts) {
	double totalBalance = 0.0;
	cout << "目前的账户: " << accounts.size() << endl;
	for (auto& account : accounts) {
		totalBalance += account.getBalance();
		cout << "卡号: " << account.getCardNo() << ", 余额: " << account.getBalance() << endl;
	}
	cout << "总余额: " << totalBalance << endl;
}