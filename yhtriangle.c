
//a[3][2] = a[2][1]+a[2][2]
//a[4][2] = a[3][1]+a[3][2],a[4][3] = a[3][2]+a[3][3]
//a[5][2] = a[4][1]+a[4][2],a[5][3] = a[4][2]+a[4][3],a[5][4] = a[4][3]+a[4][4]
int Getvalue(int line,int column)
{
	if(column == 1||line == column)
		return 1;
	else
		return (Getvalue(line-1,column-1)+Getvalue(line-1,column));
}