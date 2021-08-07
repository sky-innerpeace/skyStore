#include <iostream>
#include "MainHandler.h"
#include "ConsumerHandler.h"
#include "SellerHandler.h"
#include "StoreCommonDecl.h"

using namespace std;

int main() {
	MainHandler mainManager;

	mainManager.showMessage();
	mainManager.showSelectMode();


}