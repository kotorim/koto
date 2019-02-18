struct Pos
{
	int x;
	int y;
	int backup;
};
void mainUI(int &mapx, int &mapy, int **map);
void buildemptymap(int **map, int mapx, int mapy, int inside[]);
void rand(int**map, int mapx, int mapy, Pos &posA);
void drawmap(int **map, int mapx, int mapy, Pos &posA, Pos &space1);
void move(int **map, int mapx, int mapy, Pos &posA, Pos &space1, int &ischoosedone,int &backtomainUI);
void deleteone(int **map, int mapx, int mapy, Pos &posA, int posx, int posy, Pos &space1);
