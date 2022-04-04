#include<memory>
#include<iostream>


class Player
{
public:
	Player() : id(10)
	{
		pHaveWeaponID = new int[10];
		std::cout << "플레이어 무기 할당" << std::endl;
	}

	virtual ~Player()
	{
		std::cout << "플레이어 무기 해제" << std::endl;
		delete[] pHaveWeaponID;
		pHaveWeaponID = nullptr;
	};

	void PrintHaveWeapon()
	{
		std::cout << "플레이어 무기 장착 ID: " << id << std::endl;
	}

private:
	int id;
	int* pHaveWeaponID;
};

using namespace std;

class FPSPlayer
{
public:
	FPSPlayer(const string& name) : mLv(1), mName(name)
	{
		cout << "FPSPlayer : " << mName << " 			" << endl;
	}
	~FPSPlayer() {
		cout << "FPSPlayer : " << mName << " 			" << endl;
	}

	void setTeamPlayer(shared_ptr<FPSPlayer>& player) {
		if (player == nullptr) {
			return;
		}
		mTeamPlayer = player;
		cout << "TeamPlayer Name : " << mTeamPlayer -> mName << endl;
	}

private:
	int mLv;
	string mName;
	shared_ptr<FPSPlayer> mTeamPlayer;
};

void runFunction()
{
	std::unique_ptr<Player> redPlayer(new Player());
	redPlayer->PrintHaveWeapon();
}

void weakTest()
{
	auto pRedPlayer = make_shared<FPSPlayer>("RedPlayer");
	auto pBluePlayer = make_shared<FPSPlayer>("BluePlayer");

	weak_ptr<FPSPlayer> pWeakRedPlayer(pRedPlayer);
	shared_ptr<FPSPlayer>connectPlayer = pWeakRedPlayer.lock();
	if (connectPlayer.use_count() > 0) {
		connectPlayer->setTeamPlayer(pBluePlayer);
	}


	//pRedPlayer->setTeamPlayer(pBluePlayer);
	//pBluePlayer->setTeamPlayer(pRedPlayer);
}

int main()
{
	//runFunction();
	weakTest();
	return 0;
}