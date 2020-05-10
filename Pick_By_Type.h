 
#include"Actions/Action.h"
#include<cstdlib>
#include<ctime>
#include "Ctriangle.h"
#include"Cline.h"
#include"Figures/CRectangle.h"
#include"CRhombus.h"
#include"CEllipse.h"


class Pick_By_Type :public Action 
{         
public:
	Pick_By_Type(ApplicationManager *);
	void ReadActionParameters();
	 void Execute() ;
	~Pick_By_Type(void);
};

