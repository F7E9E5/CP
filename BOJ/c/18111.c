#include <stdio.h>

int main() {
	int i, j, k;
	int N, M, B; //����, ����, ��� ���� 
	scanf("%d %d %d", &N, &M, &B);
	
	int height;
	int blockNumber[300] = { 0 }; //� ���� �����ϴ� ��� ��  
	int maxHeight = -1, minHeight = 300;
	for (i = 0; i < N; i++) {
		for (j = 0; j < M; j++)  {
			scanf("%d", &height);
			
			if (height < minHeight) minHeight = height;
			else if (height > maxHeight) maxHeight = height;
				
			for (k = 1; k <= height; k++) blockNumber[k]++;
		}
	}
	
	int last = maxHeight + 1;	 
	int time[300] = { 0 };	 
	for (i = minHeight; i <= maxHeight; i++) {		//�ְ� ���̸� i�� �����  ���̽��� ���� 
		int Btemp = B;
		
		for (j = minHeight; j < i; j++) {			//�ּ� ���̿������� ����� �״´� 
			int temp = N * M - blockNumber[j + 1];
			time[i] += temp;
			Btemp -= temp;
		}
		
		for (j = i; j < maxHeight; j++) {				//�ְ� ���̿�������	��´�
			time[i] += blockNumber[j + 1] * 2; 			 
			Btemp += blockNumber[j + 1]; 					//���� ����� �κ��丮�� 
		}
		
		if (Btemp < 0) {		//��� ������ ���ڶ�� �Ұ����� �����̹Ƿ� ���� 
			last = i;		//last�� ���ʷ� �Ұ����� �����̴�. 
			break;
		}
		
	}
	
	int result = minHeight;
	for (i = minHeight + 1; i < last; i++) 			//�ְ����� ���̰� minHeight���� last-1�� 
		if (time[result] >= time[i]) result = i;	//���̽� �� �ϳ��� ������ �����Ѵ� 
	printf("%d %d", time[result], result);
	
	return 0;
}
