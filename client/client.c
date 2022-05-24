/*************************************************************************
> File Name: client.c
> Author: CarlSun
> Mail:sunxiuyang04@gmail.com
> Created Time: Sat Aug 20 21:30:54 2016
 ************************************************************************/

#include"../share/gomoku.h"
#include"../share/my_socket.h"
#define IP "127.0.0.1"
#define PORT 8888

void gomoku_show(char gomoku[][10]){
	int i,j;
	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			printf("%c ",gomoku[i][j]);
		}
		printf("\n");
	}
}

void gomoku_init(char gomoku[][10]){
	int i,j;
	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			gomoku[i][j]='_';
		}
	}
	for(i=0;i<N;i++)
		gomoku[0][i]=gomoku[i][0]=(i+'0');

}

int main(){
	char gomoku[N][N];
	SA server_addr;
	int msg[2];
	int fd_socket,index,sendlen=0,recvlen=0;
	my_socketCli(&fd_socket,MY_TCP,IP,PORT,&server_addr);
	my_connect(fd_socket,(pSA)&server_addr,sizeof(SA));
	printf("client start\n");
	gomoku_init(gomoku);
	int x,y;
	while(1){
		//client下棋
loop:
		printf("client 请下棋：\n");
		scanf("%d %d",&x,&y);
		if(gomoku[x][y]!='_'){
			printf("这个位置已经有棋子了\n");
			goto loop;
		}
		if(x<1||x>9 ||y<1||y>9){
				printf("范围不对\n");
				goto loop;
		}
		gomoku[x][y]='x';
		gomoku_show(gomoku);
		if(checkWin(x,y,gomoku,'x')){
			printf("client win\n");
			//发送结束指令到server
			msg[0] = 'g';
			msg[1] = 'g';
			my_send(&sendlen,fd_socket,msg,recvlen);
			break;
		}
		msg[0]=x;msg[1]=y;
		my_send(&sendlen,fd_socket,msg,8);
		printf("请等待server下棋\n");
		my_recv(&recvlen,fd_socket,msg,1024);
		if('g' == msg[0] && 'g' == msg[1]){
			printf("you lose!\n");
			break;
		}
		gomoku[msg[0]][msg[1]]='*';
		gomoku_show(gomoku);
	}

	my_close(fd_socket);
}
