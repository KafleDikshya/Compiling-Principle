#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<ctype.h>

//�궨��
//gramma.c����
//���뵥�����Ͷ���
#define CONSY 1                   //const
#define INTSY 2                   //int
#define CHARSY 3                  //char
#define VOIDSY 4                  //void
#define MAINSY 5                  //main
#define DOSY 6                    //do
#define WHISY 7                   //while
#define SWISY 8                   //switch
#define CASESY 9                  //case
#define IFSY 10                   //if
#define SCANSY 11                 //scanf
#define PRISY 12                  //printf
#define RTSY 13                   //return          ǰ13���Ǳ�����
#define IDSY 14                   //��ͨ��ʶ��
#define PLUSSY 15                 //+
#define MINUSSY 16                //-
#define STARSY 17                 //*
#define DIVSY 18                  //'/'
#define COMMASY 19                //,
#define COLONSY 20                //:
#define LPARSY 21                 //(
#define RPARSY 22                 //)
#define LBRASY 23                 //[
#define RBRASY 24                 //]
#define LBRASSY 25                //{
#define RBRASSY 26                //}
#define ASSIGNSY 27               //=
#define EQUSY 28                  //==
#define GTRSY 29                  //>
#define GTESY 30                  //>=
#define LTSY 31                   //<
#define LESY 32                   //<=
#define NEQSY 33                  // !=
#define DIGITSY 34                //�޷�������
#define CHAR2SY 35                //�ַ�
#define STRINGSY 36               //�ַ���
#define SEMISY 37                 //;

#define MAXLIST 1024
#define MAXNAME 50
#define MAXFUNC 100

//mid_code.c����
#define MAX_MID_CODE 1024

//optimizer.c����
#define MAX_FUNC_BLOCK 128
#define MAX_BASIC_BLOCK 256
#define MAX_NODE_NUM 100
#define MAX_NUM_ONE_NODE 10

//error.c����
#define FILE_OPEN_FAIL 0                                  //δ�ܴ򿪴������ļ�
//�����Ǵʷ������еı���
#define ZERO_START_ERROR 1                                //�����������0��ͷ
#define INVALID_CHAR_ERROR 2                              //�ַ��е�char�ǷǷ���
#define NO_MATCH_SQ_ERROR 3                               //�����Ų�ƥ��
#define NO_MATCH_DQ_ERROR 4                               //˫���Ų�ƥ��
#define INVALID_CHARACTER_ERROR 5                         //�ļ��г����﷨�����ܵĳɷ�
#define OUT_OF_BOUND_ERROR 6                              //���ͳ�����ֵ����int
//�������﷨����������еı���
#define OUT_OF_TABLE_ERROR 7                              //���ű��������޷�����µı�ʶ��
#define PARA_NUM_ERROR 8                                  //���ú���ʱ��ֵ�κ�ԭ����������βε���Ŀ��ͬ
#define FUNC_REDEF_ERROR 9                                //���庯��ʱ�����ַ��ű��Ѿ���ͬ���ĺ���
#define VAR_REDEF_ERROR 10                                //��ͬ�����Ѿ���ͬ����������
#define ID_ERROR 11                                       //�����ͱ�ʶ�����治�ǵ�sym���Ǳ�ʶ��
#define CONST_DEF_ASSIGN_ERROR 12                         //�ڳ��������У�Ӧ���ǵȺŵ�λ�ò��ǵȺ�
#define CONST_DEF_TYPE_ERROR 13                           //���������У��Ⱥź����sym�����ͺͳ�����������Ͳ�һ�»���sym�������������ַ�
#define CONST_DEC_TYPE_ERROR 14                           //���������У����������ͱ�ʶ������int��char
#define SEMI_ERROR 15                                     //Ӧ���Ƿֺŵĵط����ɱ��sym����
#define VAR_DEF_ARRAYINDEX_ERROR 16                       //���������У���������������޷�������
#define RPAR_ERROR 17                                     //Ӧ��ʱ��С���ŵĵط�sym���Ͳ���ȷ
#define RBRA_ERROR 18                                     //Ӧ��ʱ�������ŵĵط�sym���Ͳ���ȷ
#define RBRAS_ERROR 19                                    //Ӧ��ʱ�Ҵ����ŵĵط�sym���Ͳ���ȷ
#define VAR_KIND_ERROR 20                                 //������еı�ʶ�����Ǳ���
#define MAINSY_ERROR 21                                   //Ӧ����main�����ֵĵط�sym���ʹ���
#define LPAR_ERROR 22                                     //Ӧ��ʱ��С���ŵĵط�sym���Ͳ���ȷ
#define LBRAS_ERROR 23                                    //Ӧ��ʱ������ŵĵط�sym���Ͳ���ȷ
#define AFTER_OP_DIGIT_ERROR 24                           //�������У�+-�ź���Ĳ����޷�������
#define FACTOR_ERROR 25                                   //��factor��������Ϊ������Ĳ��ֲ���factor,��ʶ���ʶ��ĵ�һ��sym������factor����һ����֧
#define STATE_AFTER_ID_ERROR 26                           //�����ɷַ����У������˱�ʶ����Ϊ��ʼ��������治��=,(,[�е�һ�֣�����Ҫ����
#define WRONG_RELA_OP_ERROR 27                            //����Ĺ�ϵ�����
#define WHILESY_ERROR 28                                  //ѭ������У�������do��state��Ӧ����while�����֣�������Ϊ����
#define READ_ARRAY_ERROR 29                               //������У�ֻ�ܽ������ֵ�浽��ͨ������
#define VOID_RT_ERROR 30                                  //��������У�void������return������ֵ
#define VAL_RT_ERROR 31                                   //��������У���void������return����û��ֵ
#define NOT_VOID_MAIN_ERROR 32                            //main��������ʱǰ�治��void
#define ID_DEC_ERROR 33                                   //��ʶ������ʱ������Ӧ���Ƕ��š���С���š��������Ż��߷ֺţ���������ı�ʶ������Ϊ�����ʽ(��)
#define NO_RT_FUNDEF_ERROR 34                             //�з���ֵ��������ʱû�з������
#define CASE_ERROR 35                                     //Ӧ����case�ĵط���������symbol
#define CASE_CONST_ERROR 36                               //case����Ӧ���ǳ����������򱨴�
#define COLON_ERROR 37                                    //Ӧ����ð�ŵĵط�������symbol
#define ASSIGN_ERROR 38                                   //Ӧ����=�ĵط�������symbol
#define FUNC_NO_DEF_ERROR 39                              //���õĺ���δ������߲��������Ͳ���
#define ID_NO_DEF_ERROR 40                                //��ʶ��δ����������Ͳ�ƥ��
//�м���������еı���
#define OUT_OF_CODE_ERROR 41                              //�м����ṹ�������������ٴ�Ŵ���
//�﷨�����������ӵ�����
#define CONST_ASSIGNMENT_ERROR 42                         //��������ֵ
#define ARRAY_ASSIGNMENT_ERROR 43                         //�������ֱ�ֱ�Ӹ�ֵ
#define CHAR_ASSIGNMENT_ERROR 44                          //char���ܱ�int��ֵ
//�Ż��еı���������ʾ�Լ�
#define OUT_OF_FUNC_BLOCK_ERROR 45                        //������̫��
#define OUT_OF_BASIC_BLOCK_ERROR 46                       //������̫��
#define OUT_OF_NODE_NUM 47                                //�ڵ����ߵ��������dag�Ľڵ���Ŀ̫��
#define OUT_OF_ONE_NODE_VAR 48                            //һ���ڵ��ϵı���������

//��������
//gramm.c�����
int symbol;                   //����ĵ������ͺ�
//������Ƶ�ȫ�ֱ���
//1.�����ֳ��õ�
int pre_symbol;               //��ʱ��¼symbol
char pre_ch;                  //��ʱ��¼CHAR
int pre_line_index;           //��ʱ��¼index_in_line
char PRETOKEN[100];            //����������ʱ����ʱ��¼TOKEN��ֵ
//2.����ű��õ�ȫ�ֱ���
//(0)���õ�
int address = 0;                  //����ڵ�ǰAR��ƫ�Ƶ�ַ
char TEMP[100];
int array_flag = 0;               //��ʶ���ǲ�������
int var_flag = 0;
int const_flag = 0;
int para_flag = 0;
int global_flag = 0;              //��ǰ�ı������߳����ǲ���ȫ�ֵ�
//(1)���������͵�������Ҫ��
int type_symbol;              //�ں��������м�¼������type
char func_name[100];           //��¼�������ƣ������Ͳ�����Ӧ��
int para_num;                 //��¼�����Ĳ��������������
int rt_flag;                  //����з���ֵ�����ǲ�����return���
int main_flag = 0;            //�ڴ���RT���ʱ�������main��ֱ���˳�
int void_flag = 0;
int val_flag = 0;
//(2)������������Ҫ��
char name_of_id[100];          //���ڼ�¼��ʶ��������(���������ͱ���������)
int var_type;                 //���������м�¼���������� ���� ����������
int var_array_size;           //���������м�¼��������Ĵ�С
//(3)������������Ҫ��
int const_type;               //���������м�¼����������
int const_value;              //���������м�¼������ֵ
//(4)���ʽ����Ҫ��
int rela_op_symbol;           //��ϵ�������symbolֵ
int factor_type = 0;              //��¼��ǰfactor������
char now_result[100];


//final_result.c
char now_func_name[100];
int new_const_flag = 0;
int new_var_flag = 0;
int new_para_flag = 0;
int new_global_flag = 0;


//wordtest.c
///ȫ�ֳ���˵��
const char CON[] = "const";
const char INT[] = "int";
const char _CHAR[] = "char";
const char VOID[] = "void";
const char MAIN[] = "main";
const char DO[] = "do";
const char WHILE[] = "while";
const char SWITCH[] = "switch";
const char CASE[] = "case";
const char IF[] = "if";
const char SCANF[] = "scanf";
const char PRINTF[] = "printf";
const char RETURN[] = "return";
const int imax = 2147483647;  //������Ҫ������ֵ
//ȫ�ֱ�������
char CHAR;
char TOKEN[100];     //�ʷ����������Ӳ�ͬ�ַ���ɱ�ʶ�����߶�����
char read_line[512];
long trans_num = 0;
char out_symbol[50];
int line = 0;
int index_in_line = 0;
int line_lenth = 0;


//mid_code.c
//ȫ�ֳ���˵��
char CODE_EMPTY[] = "";   //  Ӧ���ǳ���������Ϊ�˺���������ʽ���ϣ�����ɾȥ��const
char CODE_INT[] = "INT";
char CODE_CHAR[] = "CHAR";
char CODE_CONST[] = "CONST";
char CODE_ARRAY[] = "ARRAY";
char CODE_FUNC[] = "FUNC";
char CODE_PARA[] = "PARA";
char CODE_CALL[] = "CALL";
char CODE_RT[] = "RT";
char CODE_EQU[] = "EQU";
char CODE_NEQ[] = "NEQ";
char CODE_LABEL[] = "LABEL";
char CODE_SCAN[] = "SCAN";
char CODE_PRINT[] = "PRINT";
char CODE_GOTO[] = "GOTO";
char CODE_END[] = "END";
char CODE_ZERO[] = "0";

int label_num = 0;
int var_num = 0;
int new_var_num = 0;




//�ļ�����
//main.c
FILE* compile_file;                                        //��������ļ�
FILE* output_file;                                         //�ʷ��������������ļ�

//final_result.c
FILE* final_code;
//final_result2.c
FILE* final_code2;

//mid_code.c
FILE* mid_code_file;
FILE* mid_code_file2;


//�ṹ�嶨��
//grammar.c
//���ű����
struct one_symbol {
	char name[MAXNAME];            //��ʶ������
	int kind;                 /*����
								0������
								1������
								2������
								3����������
							  */
	int type;                 /*����
								0��void(�������޷���ֵ����)
								1��int
								2: char
							  */
	int value;                /*������ֵ��ascii��
								������0
							  */
	int size;                 /*��������������
								���飺Ԫ�ظ���
								������-1
							  */
	int in_address;              //���������AR�׵�ַ��ƫ����(�����¼�׵�ַ)
};
struct table {
	struct one_symbol List[MAXLIST]; //���ű�
	int list_index;           //����
	int num_of_func;          //�Ѿ������ĺ�������
	int index_of_func[MAXFUNC]; //��ʼ��ȫ-1����ź�����table����
};
struct table Table;
struct table new_Table;
struct table new_Table2;

//mid_code.c
//�м����Ľṹ�����
struct mid_code {
	int op;
	char src1[100];
	char src2[100];
	char result[100];
	int is_effective;
};
//������洢��Ԫʽ������
struct mid_code_list {
	struct mid_code MID_CODE[MAX_MID_CODE];
	int code_num;
};
struct mid_code_list CODE_LIST;

//final_result.c
//�ڲ��ṹ����ƣ���Ÿ����Ĵ�����Ӧ�ı�������     ʹ�õĲ���ȫ��ע����
//struct reg_var {
//	char reg_name[20];
//	char var_name[100];
//	int is_var;//0: const 1: just var -1: no data
//};

//final_result2.c
//�ڲ��ṹ����ƣ���Ÿ����Ĵ�����Ӧ�ı�������
struct s_reg {
	char var_name[9][100];
	int total_var_num;
};
struct s_reg S_REG;
//optimizer.c
//����ṹ
struct func_block {
	int start_num;
	int basic_blocks[MAX_BASIC_BLOCK];
	int b_block_index;
};

struct func_blocks {
	struct func_block FUNC_LIST[MAX_FUNC_BLOCK];
	int func_index;
};

struct node {
	char name[100];
	int node_num;  //�ڵ����
};

struct node_table {
	struct node NODE_LIST[MAX_NODE_NUM];
	int var_num;
};

struct node_for_dag {
	int var_num;  //һ���ڵ��Ӧ�ı����ж���
	int op;
	int left_son_num;
	int right_son_num;
	char name[MAX_NUM_ONE_NODE][100];
};

struct like_dag {
	struct node_for_dag NODE_LIST[MAX_NODE_NUM];
	int node_num;
};
//ȫ�ֱ���
struct func_blocks FUNC_BLOCKS;
struct node_table NODE_TABLE;
struct node_table EMPTY_NODE_TABLE;
struct like_dag DAG;



//�������弰ʵ��
//���Ƕ���
//error.c
void error(int error_type, int line_index);
//grammar.c
void initial_table();
void append_to_table(char name[], int kind, int type, int value, int size, int in_address);
void append_para(int num);
int index_in_table(char name[], int kind);
int get_func_type(char name[]);
int get_const_value(char name[]);

void program();
void var_dec();
void const_dec();
void val_func_def();
void void_func_def();
void main_func();
void const_def();
void var_def();
void dec_head();
void para_list();
void comp_state();
void state_list();
void state();
void if_state();
void condition();
void rela_op();
void loop_state();
void switch_state();
void situation_list(char label[], char for_compare[]);
void case_state(char label[], char for_compare[]);
void val_fun_call2();
void val_fun_call();
void void_fun_call();
void val_para_list();
void assign_state();
void read_state();
void write_state();
void return_state();
void expr();
void term();
void factor();
//wordtest.c
int insymbol();

//mid_code.c��������
//�м����Ĳ�����������
void init_code_list();
void init_var_num();
void generate_mid_code(int op, char src1[], char scr2[], char result[]);
void generate_label(char label[]);
void generate_temp_var(char var[]);
void generate_new_temp_var(char var[]);
void print_mid_code();
void print_one_code(int number, FILE* mid_code_file);
void init_func_list();
void add_func_block();

//final_result.c����������
//��������
void get_new_Table();
void data_area_generate();
void generate_all_final_code();
void generate_text();
int new_index_in_tab(char name[]);
int get_func_para_num(char name[]);
void load_data(const char reg_name[], char var_name[]);
void store_data(const char reg_name[], char var_name[]);
int get_func_total_size(char name[]);



//֮����ʵ��
//grammar.c
//���ڷ��ű�Ĳ���
void initial_table() {
	Table.num_of_func = 0;
	Table.list_index = -1;
}
void append_to_table(char name[], int kind, int type, int value, int size, int in_address) {
	int index, func_index;
	if (Table.list_index >= (MAXLIST - 1)) {
		error(OUT_OF_TABLE_ERROR, line);
		fclose(compile_file);
		fclose(output_file);
		exit(-1);
		return;
	}
	if (kind == 2) {
		for (index = 0; index < Table.num_of_func; index++) {
			func_index = Table.index_of_func[index];
			if (strcmp(Table.List[func_index].name, name) == 0) {                   //���������ظ�
				error(FUNC_REDEF_ERROR, line);
				return;
			}
		}
		Table.index_of_func[Table.num_of_func] = Table.list_index + 1;
		Table.num_of_func++;
	}
	else {
		func_index = Table.index_of_func[Table.num_of_func - 1];
		for (index = func_index; index <= Table.list_index; index++) {
			if (strcmp(Table.List[index].name, name) == 0) {                        //��������ͬ��������
				error(VAR_REDEF_ERROR, line);
				return;
			}
		}
	}
	Table.list_index++;
	strcpy(Table.List[Table.list_index].name, name);
	Table.List[Table.list_index].kind = kind;
	Table.List[Table.list_index].type = type;
	Table.List[Table.list_index].size = size;
	Table.List[Table.list_index].value = value;
	Table.List[Table.list_index].in_address = in_address;
}
void append_para(int num) {
	int index;
	index = Table.index_of_func[Table.num_of_func - 1];
	Table.List[index].size = num;
}
int index_in_table(char name[], int kind) {                      //������
	int i, index, first_func_index;
	array_flag = 0;
	var_flag = 0;
	const_flag = 0;
	para_flag = 0;
	global_flag = 0;
	if (kind == 2) { //����
		for (i = 0; i < Table.num_of_func; i++) {
			index = Table.index_of_func[i];
			if (strcmp(name, Table.List[index].name) == 0)
				break;
		}
		if (i == Table.num_of_func) {
			error(FUNC_NO_DEF_ERROR, line);
			return -1;
		}
		else {       //�ҵ���ͬ������
			index = Table.index_of_func[i];
			if (Table.List[index].size != para_num) {
				error(PARA_NUM_ERROR, line);
				return index;
			}
			return index;
		}
	}
	else { //��ͨ��ʶ��
		index = Table.index_of_func[Table.num_of_func - 1];
		for (; index <= Table.list_index; index++) {
			if (strcmp(Table.List[index].name, name) == 0) {                        //��������ͬ��������
				break;
			}
		}
		if (index > Table.list_index) { //�����Ҳ�����ȥȫ�ֱ�����
			first_func_index = Table.index_of_func[0];
			for (index = 0; index < first_func_index; index++) {
				if (strcmp(name, Table.List[index].name) == 0)
					break;
			}
			if (index == first_func_index) {
				error(ID_NO_DEF_ERROR, line);
				printf("wrong: %s\n", name);
				return -1;
			}
			global_flag = 1;
			if (Table.List[index].kind == 1) {
				if (Table.List[index].size != -1)
					array_flag = 1;
				else
					var_flag = 1;
				return Table.List[index].type;
			}
			else if (Table.List[index].kind == 0) {
				const_flag = 1;
				return Table.List[index].type;
			}
			else if (Table.List[index].kind == 3) { //Ӧ�ò������
				para_flag = 1;
				return Table.List[index].type;
			}
		}
		else {                           //�����ҵ�
			if (Table.List[index].kind == 1) {
				if (Table.List[index].size != -1)
					array_flag = 1;
				else
					var_flag = 1;
				return Table.List[index].type;
			}
			else if (Table.List[index].kind == 0) {
				const_flag = 1;
				return Table.List[index].type;
			}
			else if (Table.List[index].kind == 3) {
				para_flag = 1;
				return Table.List[index].type;
			}
		}
	}
	return 0;
}
int get_func_type(char name[]) {
	int i, index;
	for (i = 0; i < Table.num_of_func; i++) {
		index = Table.index_of_func[i];
		if (strcmp(name, Table.List[index].name) == 0)
			break;
	}
	if (i == Table.num_of_func) {
		error(FUNC_NO_DEF_ERROR, line);
		return -1;
	}
	else {       //�ҵ���ͬ������
		return Table.List[index].type;
	}
}
int get_const_value(char name[]) {
	int index, first_func_index;
	index = Table.index_of_func[Table.num_of_func - 1];
	for (; index <= Table.list_index; index++) {
		if (strcmp(Table.List[index].name, name) == 0) {                        //��������ͬ��������
			break;
		}
	}
	if (index > Table.list_index) { //�����Ҳ�����ȥȫ�ֱ�����
		first_func_index = Table.index_of_func[0];
		for (index = 0; index < first_func_index; index++) {
			if (strcmp(name, Table.List[index].name) == 0)
				break;
		}
		if (index == first_func_index) {
			error(ID_NO_DEF_ERROR, line);
			printf("wrong: %s\n", name);
			return -1;
		}
		return Table.List[index].value;
	}
	else {                           //�����ҵ�
		return Table.List[index].value;
	}
}

//�����ֵĵݹ��ӳ���
void program() {               //����
	if (symbol == CONSY) {    //����const�ؼ���
		const_dec();
	}
	while (symbol == INTSY || symbol == CHARSY) {   //������������
		pre_ch = CHAR;                            //��Ϊint����char��ͷ�Ŀ����Ǳ����������ߺ������������������Ҫ�ָ��ֳ�
		pre_line_index = index_in_line;
		pre_symbol = symbol;       //����Ԥ��֮ǰ����Ϣ
		strcpy(PRETOKEN, TOKEN);
		symbol = insymbol();
		if (symbol != IDSY) {
			error(ID_ERROR, line);
			do {
				symbol = insymbol();
			} while (symbol != INTSY && symbol != CHARSY && symbol != VOIDSY);
			continue;
		}
		symbol = insymbol();                      //���������һ�����ʣ��Ӷ��б��Ǳ������Ǻ���(������Ӧ����С����)
		if (symbol == LPARSY) {                     //��⵽С���ţ�ȷ���Ǻ�������
			strcpy(TOKEN, PRETOKEN);               //�ָ��ֳ�������ѭ�������뺯����������
			CHAR = pre_ch;
			index_in_line = pre_line_index;
			symbol = pre_symbol;
			break;
		}
		else if (symbol == SEMISY || symbol == COMMASY || symbol == LBRASY) {   //ȷ���Ǳ�������
			strcpy(TOKEN, PRETOKEN);               //�ָ��ֳ��������������ģ��
			CHAR = pre_ch;
			index_in_line = pre_line_index;
			symbol = pre_symbol;
			var_def();
			if (symbol != SEMISY) {
				error(SEMI_ERROR, line);
				do {
					symbol = insymbol();
				} while (symbol != INTSY && symbol != CHARSY && symbol != VOIDSY);        //������һ���������߱�������
				continue;
			}
			else {
				symbol = insymbol();
			}
		}
		else {
			//����Ӧ�����������Ϣ����ʶ��������ַ�����(�Ƿ�����)����skip����һ��int��char��void
			error(ID_DEC_ERROR, line);
			do {
				symbol = insymbol();
			} while (symbol != INTSY && symbol != CHARSY && symbol != VOIDSY);        //������һ���������߱�������
			continue;
		}
	}
	while (symbol == INTSY || symbol == CHARSY || symbol == VOIDSY) {         //������������
		if (symbol == INTSY || symbol == CHARSY) {
			val_func_def();
		}
		else {
			pre_ch = CHAR;                            //��¼�ֳ�
			pre_line_index = index_in_line;
			pre_symbol = symbol;
			strcpy(PRETOKEN, TOKEN);
			symbol = insymbol();
			if (symbol == MAINSY) {
				strcpy(TOKEN, PRETOKEN);               //�ָ��ֳ���������������������ģ��
				CHAR = pre_ch;
				index_in_line = pre_line_index;
				symbol = pre_symbol;
				break;
			}
			else {
				strcpy(TOKEN, PRETOKEN);               //�ָ��ֳ��������޷���ֵ��������ģ��(�˴����Ż���)
				CHAR = pre_ch;
				index_in_line = pre_line_index;
				symbol = pre_symbol;
				void_func_def();
			}
		}
	}
	main_func();//֮ǰ�Ѿ�����˱�Ҫ�ı��������Լ���������
	fprintf(output_file, "This is a program!\n");
	//printf("This is a program!\n");
}

void var_dec() {
	while (symbol == INTSY || symbol == CHARSY) {
		var_def();
		if (symbol != SEMISY) {
			error(SEMI_ERROR, line);
			do {
				symbol = insymbol();
			} while (symbol != INTSY && symbol != CHARSY /*&& symbol != VOIDSY*/ && symbol != IFSY && symbol != DOSY && symbol != SWISY && symbol != LBRASSY && symbol != IDSY && symbol != SCANSY && symbol != PRISY && symbol != RTSY);        //������һ������������������
		}
		else {
			symbol = insymbol();
		}
	}
	fprintf(output_file, "This is a variable declaration!\n");
	//printf("This is a variable declaration!\n");
}

void const_dec() {
	while (symbol == CONSY) {
		symbol = insymbol();    //�ٶ�����һ���ַ�
		const_def();
		if (symbol != SEMISY) {   //�������֮������зֺ�
			error(SEMI_ERROR, line);
			do {
				symbol = insymbol();
			} while (symbol != CONSY && symbol != INTSY && symbol != CHARSY && symbol != VOIDSY && symbol != IFSY && symbol != DOSY && symbol != SWISY && symbol != LBRASSY && symbol != IDSY && symbol != SCANSY && symbol != PRISY && symbol != RTSY);        //������һ�䳣���������߱��������������
		}
		else {
			symbol = insymbol();
		}
	}
	fprintf(output_file, "This is a constant declaration!\n");
	//printf("This is a constant declaration!\n");
}

void val_func_def() {
	type_symbol = symbol;
	rt_flag = 0;
	dec_head();
	if (symbol == LPARSY) {
		val_flag = 1;
		void_flag = 0;
		if (type_symbol == CHARSY) {
			//����������+�������char
			generate_mid_code(8, func_name, CODE_EMPTY, CODE_EMPTY);
			add_func_block();
		}
		else {
			//����������+�������int
			generate_mid_code(7, func_name, CODE_EMPTY, CODE_EMPTY);
			add_func_block();
		}
		symbol = insymbol();
		para_list();
		if (symbol == RPARSY) {
			symbol = insymbol();
			if (symbol == LBRASSY) {
				symbol = insymbol();
				comp_state();
				if (symbol == RBRASSY) {
					symbol = insymbol();
					if (rt_flag == 0) {
						printf("%s\n", func_name);
						error(NO_RT_FUNDEF_ERROR, line);
					}
					//������Ԫʽ�������Ľ������?
					rt_flag = 0;
					fprintf(output_file, "This is a value function defination!\n");
					//printf("This is a value function defination!\n");
					return;
				}
				else {
					error(RBRAS_ERROR, line);
					do {
						symbol = insymbol();
					} while (symbol != VOIDSY && symbol != INTSY && symbol != CHARSY);
					return;
				}
			}
			else {
				error(LBRAS_ERROR, line);
				do {
					symbol = insymbol();
				} while (symbol != RBRASSY);
				symbol = insymbol();
				return;
			}
		}
		else {
			error(RPAR_ERROR, line);
			do {
				symbol = insymbol();
			} while (symbol != RBRASSY);
			symbol = insymbol();
			return;
		}
	}
	else {
		error(LPAR_ERROR, line);
		do {
			symbol = insymbol();
		} while (symbol != RBRASSY);
		symbol = insymbol();
		return;
	}
}

void void_func_def() {
	type_symbol = VOIDSY;
	symbol = insymbol();
	if (symbol == IDSY) {
		strcpy(func_name, TOKEN);
		//����������+�������void
		void_flag = 1;
		val_flag = 0;
		generate_mid_code(9, func_name, CODE_EMPTY, CODE_EMPTY);
		add_func_block();
		address = 0;
		append_to_table(func_name, 2, 0, 0, 0, address);
		symbol = insymbol();
		if (symbol == LPARSY) {
			symbol = insymbol();
			para_list();
			if (symbol == RPARSY) {
				symbol = insymbol();
				if (symbol == LBRASSY) {
					symbol = insymbol();
					comp_state();
					if (symbol == RBRASSY) {
						symbol = insymbol();
						//������Ԫʽ�������Ľ������
						generate_mid_code(25, CODE_EMPTY, CODE_EMPTY, CODE_EMPTY);
						//generate_mid_code(37,CODE_EMPTY,CODE_EMPTY,CODE_EMPTY);
						fprintf(output_file, "This is a void function defination!\n");
						//printf("This is a void function defination!\n");
						return;
					}
					else {
						error(RBRAS_ERROR, line);
						do {
							symbol = insymbol();
						} while (symbol != VOIDSY && symbol != INTSY && symbol != CHARSY);
						return;
					}
				}
				else {
					error(LBRAS_ERROR, line);
					do {
						symbol = insymbol();
					} while (symbol != RBRASSY);
					symbol = insymbol();
					return;
				}
			}
			else {
				error(RPAR_ERROR, line);
				do {
					symbol = insymbol();
				} while (symbol != RBRASSY);
				symbol = insymbol();
				return;
			}
		}
		else {
			error(LPAR_ERROR, line);
			do {
				symbol = insymbol();
			} while (symbol != RBRASSY);
			symbol = insymbol();
			return;
		}
	}
	else {
		error(ID_ERROR, line);
		do {
			symbol = insymbol();
		} while (symbol != RBRASSY);
		symbol = insymbol();
		return;
	}
}

void main_func() {   //�ҿ�����������Ĳ���
	if (symbol != VOIDSY) {           //�����������ֻ��VOID���ͣ����ܽ��������Ŀ�����
		error(NOT_VOID_MAIN_ERROR, line);
		return;                             //���Ķ�ô��
	}
	symbol = insymbol();
	if (symbol == MAINSY) {
		//���+������Ԫʽ
		strcpy(func_name, TOKEN);
		val_flag = 0;
		void_flag = 1;
		main_flag = 1;
		generate_mid_code(9, func_name, CODE_EMPTY, CODE_EMPTY);   ///��������������м����ĺ���
		add_func_block();
		address = 0;
		append_to_table(func_name, 2, 0, 0, 0, address);
		symbol = insymbol();
		if (symbol != LPARSY) {      //   ��
			error(LPAR_ERROR, line);
			do {
				symbol = insymbol();
			} while (symbol != LBRASSY);   //[
		}
		else {
			symbol = insymbol();    //����   ���������
		}
		if (symbol != RPARSY) {     //Ҫ��main�������治�����κεĲ���
			error(RPAR_ERROR, line);
			do {
				symbol = insymbol();
			} while (symbol != LBRASSY);
		}
		else {
			symbol = insymbol();
		}
		if (symbol != LBRASSY) {   //֮�����ֱ�Ӵ�����{
			error(LBRAS_ERROR, line);
			return;
		}
		symbol = insymbol();
		comp_state();   //���������������������������ĸ�����Ϣ������ֻ������һ��
		if (symbol == RBRASSY) {
			//������Ԫʽ�������Ľ������
			generate_mid_code(34, CODE_EMPTY, CODE_EMPTY, CODE_EMPTY);
			fprintf(output_file, "This is a main function defination!\n");
			//sprintf("This is a main function defination!\n");
			return;
		}
		else {
			error(RBRAS_ERROR, line);
			return;
		}
	}
	else {
		error(MAINSY_ERROR, line);
		return;                             //���Ķ�ô��
	}
}

void const_def() {      //�������岿��
	int sign = 1;   //1:+ 0:-
	if (symbol == INTSY || symbol == CHARSY) {     //ȷ����int����char
		const_type = symbol;
		do {
			symbol = insymbol();
			if (symbol == IDSY) {       //������ͨ��ʶ��
				strcpy(name_of_id, TOKEN);
				symbol = insymbol();
				if (symbol == ASSIGNSY) {      //����=
					symbol = insymbol();
					if (symbol == PLUSSY || symbol == MINUSSY) {//   ����+/-
						sign = (symbol == PLUSSY) ? 1 : 0;   //ȷ������
						symbol = insymbol();
						if (symbol == DIGITSY || const_type == INTSY) {      //֮�������ֻ���int����
							if (trans_num == 0) {       //�����Ǳ����ˣ���������������־��ǵ�����0��ô�죿����
								error(AFTER_OP_DIGIT_ERROR, line);
								do {
									symbol = insymbol();
								} while (symbol != COMMASY && symbol != SEMISY);   //,��;
								continue;
							}
							if (sign == 1)
								const_value = trans_num;
							else
								const_value = 0 - trans_num;
							address = address + 1;
							append_to_table(name_of_id, 0, 1, const_value, -1, address);
							sprintf(TEMP, "%d", const_value);
							generate_mid_code(1, name_of_id, TEMP, CODE_EMPTY);
							//���������Ԫʽ
							symbol = insymbol();
							fprintf(output_file, "This is an integer!\n");
							//printf("This is an integer!\n");
						}
						else {
							error(CONST_DEF_TYPE_ERROR, line);
							do {
								symbol = insymbol();
							} while (symbol != COMMASY && symbol != SEMISY);
							continue;
						}
					}
					else if (symbol == DIGITSY && const_type == INTSY) {
						sign = 1;
						const_value = trans_num;
						//���������Ԫʽ
						address = address + 1;
						append_to_table(name_of_id, 0, 1, const_value, -1, address);
						sprintf(TEMP, "%d", const_value);
						generate_mid_code(1, name_of_id, TEMP, CODE_EMPTY);
						symbol = insymbol();
						fprintf(output_file, "This is an integer!\n");
						//printf("This is an integer!\n");
					}
					else if (symbol == CHAR2SY && const_type == CHARSY) {
						sign = 1;
						const_value = TOKEN[1];
						//���������Ԫʽ
						address = address + 1;
						append_to_table(name_of_id, 0, 2, const_value, -1, address);
						sprintf(TEMP, "%d", const_value);
						generate_mid_code(2, name_of_id, TEMP, CODE_EMPTY);
						symbol = insymbol();
						fprintf(output_file, "This is a char!\n");
						//printf("This is a char!\n");
					}
					else {
						error(CONST_DEF_TYPE_ERROR, line);
						do {
							symbol = insymbol();
						} while (symbol != COMMASY && symbol != SEMISY);
						continue;
					}
				}
				else {
					error(CONST_DEF_ASSIGN_ERROR, line);
					do {
						symbol = insymbol();
					} while (symbol != COMMASY && symbol != SEMISY);
					continue;
				}
			}
			else {
				error(ID_ERROR, line);
				do {
					symbol = insymbol();
				} while (symbol != COMMASY && symbol != SEMISY);
				continue;                                 //?
			}
		} while (symbol == COMMASY);
		fprintf(output_file, "This is a constant defination!\n");
		//printf("This is a constant defination!\n");
		return;
	}
	else {
		error(CONST_DEC_TYPE_ERROR, line);   //const֮�� �������int����char��Ȼ����
		do {
			symbol = insymbol();
		} while (symbol != SEMISY);
		return;
	}
}

void var_def() {
	int real_type;
	var_type = symbol;
	if (var_type == INTSY) {
		real_type = 1;
	}
	else {
		real_type = 2;
	}
	do {
		symbol = insymbol();
		if (symbol == IDSY) {
			strcpy(name_of_id, TOKEN);
			symbol = insymbol();
			var_array_size = 0;
			if (symbol == COMMASY || symbol == SEMISY) {
				//����ͨ�������ñ������
				address = address + 1;
				append_to_table(name_of_id, 1, real_type, 0, -1, address);
				if (real_type == 1) {
					generate_mid_code(3, name_of_id, CODE_EMPTY, CODE_EMPTY);
				}
				else {
					generate_mid_code(4, name_of_id, CODE_EMPTY, CODE_EMPTY);
				}
				continue;
			}
			else if (symbol == LBRASY) {         //����
				symbol = insymbol();
				if (symbol == DIGITSY) {
					var_array_size = trans_num;
					if (var_array_size != 0) {
						symbol = insymbol();
						if (symbol == RBRASY) {
							//����������֡���С�����͵����
							address = address + var_array_size;
							append_to_table(name_of_id, 1, real_type, 0, var_array_size, address);
							sprintf(TEMP, "%d", var_array_size);
							if (real_type == 1) {
								generate_mid_code(5, name_of_id, TEMP, CODE_EMPTY);
							}
							else {
								generate_mid_code(6, name_of_id, TEMP, CODE_EMPTY);
							}
							symbol = insymbol();
						}
						else {
							error(RBRA_ERROR, line);         //0�����޷�������
							do {
								symbol = insymbol();
							} while (symbol != COMMASY && symbol != SEMISY);
							continue;
						}
					}
					else {
						error(VAR_DEF_ARRAYINDEX_ERROR, line);         //0�����޷�������
						do {
							symbol = insymbol();
						} while (symbol != COMMASY && symbol != SEMISY);
						continue;
					}
				}
				else {
					error(VAR_DEF_ARRAYINDEX_ERROR, line);
					do {
						symbol = insymbol();
					} while (symbol != COMMASY && symbol != SEMISY);
					continue;
				}
			}
			else {
				error(ID_DEC_ERROR, line);          //��ʶ����ʽ����
				do {
					symbol = insymbol();
				} while (symbol != COMMASY && symbol != SEMISY);
				continue;
			}
		}
		else {
			error(ID_ERROR, line);
			do {
				symbol = insymbol();
			} while (symbol != COMMASY && symbol != SEMISY);
			continue;
		}
	} while (symbol == COMMASY);
	fprintf(output_file, "This is a variable defination!\n");
	//printf("This is a variable defination!\n");
}

void dec_head() {
	int real_type;
	if (type_symbol == INTSY) {
		real_type = 1;
	}
	else {
		real_type = 2;
	}
	symbol = insymbol();
	if (symbol == IDSY) {
		strcpy(func_name, TOKEN);
		address = 0;
		append_to_table(func_name, 2, real_type, 0, 0, address);
		//������������+�������
		symbol = insymbol();
		fprintf(output_file, "This is a defination head!\n");
		//printf("This is a defination head!\n");
		return;
	}
	else {
		error(ID_ERROR, line);
		return;
	}
}

void para_list() {
	int real_type;
	para_num = 0;
	do {
		if (symbol == COMMASY) {
			symbol = insymbol();
		}
		if (symbol == INTSY || symbol == CHARSY) {
			var_type = symbol;
			if (var_type == INTSY) {
				real_type = 1;
			}
			else {
				real_type = 2;
			}
			symbol = insymbol();
			if (symbol == IDSY) {
				para_num++;
				strcpy(name_of_id, TOKEN);
				address = address + 1;
				append_to_table(name_of_id, 3, real_type, 0, -1, address);
				if (real_type == 1) {
					generate_mid_code(10, name_of_id, CODE_INT, CODE_EMPTY);
				}
				else {
					generate_mid_code(10, name_of_id, CODE_CHAR, CODE_EMPTY);
				}
				//�������(������var_type��)
				symbol = insymbol();
			}
			else {
				error(ID_ERROR, line);
				do {
					symbol = insymbol();
				} while (symbol != RPARSY);
				return;
			}
		}
	} while (symbol == COMMASY);
	append_para(para_num);
	//�Ѻ����Ĳ�������������
	fprintf(output_file, "This is a parameter list!\n");
	//printf("This is a parameter list!\n");
}

void comp_state() {     //��ô�ֿܷ�д���������������֮��
	if (symbol == CONSY) {        //�����˳������弰��������
		const_dec();
	}
	if (symbol == INTSY || symbol == CHARSY) {
		var_dec();
	}
	state_list();
	fprintf(output_file, "This is a composite statement!\n");
	//printf("This is a composite statement!\n");
}

void state_list() {    //������ᴦ�����п��ܵ���䲢��������if,do,switch,{,��ʶ����scanf��printf,;,return
	while (symbol == IFSY || symbol == DOSY || symbol == SWISY || symbol == LBRASSY || symbol == IDSY || symbol == SCANSY || symbol == PRISY || symbol == SEMISY || symbol == RTSY) {
		state();
	}
	fprintf(output_file, "This is a statement list!\n");//����״̬���
	//printf("This is a statement list!\n");
}

void state() {
	int func_type;
	init_var_num();
	if (symbol == IFSY) {
		if_state();
	}
	else if (symbol == DOSY) {
		loop_state();
	}
	else if (symbol == SWISY) {
		switch_state();
	}
	else if (symbol == LBRASSY) {   //����������϶��ӵ�������������
		symbol = insymbol();
		state_list();
		if (symbol == RBRASSY) {
			symbol = insymbol();
		}
		else {
			error(RBRAS_ERROR, line);
			do {
				symbol = insymbol();
			} while (symbol != IFSY && symbol != DOSY && symbol != SWISY && symbol != LBRASSY && symbol != IDSY && symbol != SCANSY && symbol != PRISY && symbol != SEMISY && symbol != RTSY);
			return;
		}
	}
	else if (symbol == IDSY) {
		//�������߸�ֵ
		pre_ch = CHAR;                            //��¼�ֳ�
		pre_line_index = index_in_line;
		pre_symbol = symbol;
		strcpy(PRETOKEN, TOKEN);
		symbol = insymbol();
		if (symbol == LPARSY) {
			//��������
			strcpy(TOKEN, PRETOKEN);               //�ָ��ֳ������뺯�����ô���
			CHAR = pre_ch;
			index_in_line = pre_line_index;
			symbol = pre_symbol;                  //��һ��������
			func_type = get_func_type(TOKEN);
			//���ȷ�������ֺ�������ʱ��д������
			if (func_type == 0) {
				void_fun_call();
			}
			else if (func_type == 1 || func_type == 2) {
				val_fun_call();
			}
			else {
				error(FUNC_NO_DEF_ERROR, line);
				do {
					symbol = insymbol();
				} while (symbol != IFSY && symbol != DOSY && symbol != SWISY && symbol != LBRASSY && symbol != IDSY && symbol != SCANSY && symbol != PRISY && symbol != SEMISY && symbol != RTSY);
				return;
			}
			if (symbol == SEMISY) {
				symbol = insymbol();
				fprintf(output_file, "This is a statement!\n");
				//printf("This is a statement!\n");
				return;
			}
			else {
				error(SEMI_ERROR, line);
				do {
					symbol = insymbol();
				} while (symbol != IFSY && symbol != DOSY && symbol != SWISY && symbol != LBRASSY && symbol != IDSY && symbol != SCANSY && symbol != PRISY && symbol != SEMISY && symbol != RTSY);
				return;
			}
		}
		else if (symbol == ASSIGNSY || symbol == LBRASY) {
			strcpy(TOKEN, PRETOKEN);               //�ָ��ֳ������븳ֵ��䴦��
			CHAR = pre_ch;
			index_in_line = pre_line_index;
			symbol = pre_symbol;
			assign_state();
			if (symbol == SEMISY) {
				symbol = insymbol();
				fprintf(output_file, "This is a statement!\n");
				//printf("This is a statement!\n");
				return;
			}
			else {
				error(SEMI_ERROR, line);
				do {
					symbol = insymbol();
				} while (symbol != IFSY && symbol != DOSY && symbol != SWISY && symbol != LBRASSY && symbol != IDSY && symbol != SCANSY && symbol != PRISY && symbol != SEMISY && symbol != RTSY);
				return;
			}
		}
		else {
			error(STATE_AFTER_ID_ERROR, line);
			do {
				symbol = insymbol();
			} while (symbol != IFSY && symbol != DOSY && symbol != SWISY && symbol != LBRASSY && symbol != IDSY && symbol != SCANSY && symbol != PRISY && symbol != SEMISY && symbol != RTSY);
			return;
		}
	}
	else if (symbol == SCANSY) {
		read_state();
		if (symbol == SEMISY) {
			symbol = insymbol();
		}
		else {
			error(SEMI_ERROR, line);
			do {
				symbol = insymbol();
			} while (symbol != IFSY && symbol != DOSY && symbol != SWISY && symbol != LBRASSY && symbol != IDSY && symbol != SCANSY && symbol != PRISY && symbol != SEMISY && symbol != RTSY);
			return;
		}
	}
	else if (symbol == PRISY) {
		write_state();
		if (symbol == SEMISY) {
			symbol = insymbol();
		}
		else {
			error(SEMI_ERROR, line);
			do {
				symbol = insymbol();
			} while (symbol != IFSY && symbol != DOSY && symbol != SWISY && symbol != LBRASSY && symbol != IDSY && symbol != SCANSY && symbol != PRISY && symbol != SEMISY && symbol != RTSY);
			return;
		}
	}
	else if (symbol == RTSY) {
		return_state();
		if (symbol == SEMISY) {
			symbol = insymbol();
		}
		else {
			error(SEMI_ERROR, line);
			do {
				symbol = insymbol();
			} while (symbol != IFSY && symbol != DOSY && symbol != SWISY && symbol != LBRASSY && symbol != IDSY && symbol != SCANSY && symbol != PRISY && symbol != SEMISY && symbol != RTSY);
			return;
		}
	}
	else if (symbol == SEMISY) {
		symbol = insymbol();
	}
	else {
		return;               //��ʱ����
	}
	fprintf(output_file, "This is a statement!\n");
	//printf("This is a statement!\n");
}

void if_state() {
	char label[100];
	char condition_result[100];
	generate_label(label);
	symbol = insymbol();
	if (symbol == LPARSY) {
		symbol = insymbol();
		condition();
		strcpy(condition_result, now_result);
		generate_mid_code(22, condition_result, label, CODE_EMPTY);
		//generate_mid_code(37,CODE_EMPTY,CODE_EMPTY,CODE_EMPTY);
		if (symbol == RPARSY) {
			symbol = insymbol();
			state();
			//generate_mid_code(37,CODE_EMPTY,CODE_EMPTY,CODE_EMPTY);
			generate_mid_code(24, label, CODE_EMPTY, CODE_EMPTY);
			fprintf(output_file, "This is an if statement!\n");
			//printf("This is an if statement!\n");
			return;
		}
		else {
			error(RPAR_ERROR, line);
			do {
				symbol = insymbol();
			} while (symbol != IFSY && symbol != DOSY && symbol != SWISY && symbol != LBRASSY && symbol != IDSY && symbol != SCANSY && symbol != PRISY && symbol != SEMISY && symbol != RTSY);
			return;
		}
	}
	else {
		error(LPAR_ERROR, line);
		do {
			symbol = insymbol();
		} while (symbol != IFSY && symbol != DOSY && symbol != SWISY && symbol != LBRASSY && symbol != IDSY && symbol != SCANSY && symbol != PRISY && symbol != SEMISY && symbol != RTSY);
		return;
	}
}

void condition() {
	char num1[100];
	char num2[100];
	strcpy(num1, CODE_EMPTY);
	strcpy(num2, CODE_EMPTY);
	expr();
	strcpy(num1, now_result);
	if (symbol == EQUSY || symbol == LTSY || symbol == LESY || symbol == GTRSY || symbol == GTESY || symbol == NEQSY) {                       //������жϱ���ô������������������������
		rela_op();
		expr();
		strcpy(num2, now_result);
		generate_temp_var(now_result);
		switch (rela_op_symbol) {
		case EQUSY: {
			generate_mid_code(20, num1, num2, now_result);
			break;
		}
		case LTSY: {
			generate_mid_code(17, num1, num2, now_result);
			break;
		}
		case LESY: {
			generate_mid_code(16, num1, num2, now_result);
			break;
		}
		case GTRSY: {
			generate_mid_code(19, num1, num2, now_result);
			break;
		}
		case GTESY: {
			generate_mid_code(18, num1, num2, now_result);
			break;
		}
		case NEQSY: {
			generate_mid_code(21, num1, num2, now_result);
			break;
		}
		}
	}
	else {
		generate_temp_var(now_result);
		generate_mid_code(21, num1, CODE_ZERO, now_result);
	}
	//address = address+1;
	//append_to_table(now_result,1,1,0,-1,address);   233
	fprintf(output_file, "This is a condition!\n");
	//printf("This is a condition!\n");
}

void rela_op() {
	if (symbol == EQUSY || symbol == GTRSY || symbol == GTESY || symbol == LTSY || symbol == LESY || symbol == NEQSY) {
		rela_op_symbol = symbol;
		symbol = insymbol();
	}
	else {
		error(WRONG_RELA_OP_ERROR, line);
		do {
			symbol = insymbol();
		} while (symbol != IFSY && symbol != DOSY && symbol != SWISY && symbol != LBRASSY && symbol != IDSY && symbol != SCANSY && symbol != PRISY && symbol != SEMISY && symbol != RTSY);
		return;
	}
	fprintf(output_file, "This is a relational operation!\n");
	//printf("This is a relational operation!\n");
}

void loop_state() {
	char label1[100];
	generate_label(label1);
	//generate_mid_code(37,CODE_EMPTY,CODE_EMPTY,CODE_EMPTY);
	generate_mid_code(24, label1, CODE_EMPTY, CODE_EMPTY);
	symbol = insymbol();
	state();
	if (symbol == WHISY) {
		symbol = insymbol();
		if (symbol == LPARSY) {
			symbol = insymbol();
			condition();
			if (symbol == RPARSY) {
				symbol = insymbol();
				generate_mid_code(23, now_result, label1, CODE_EMPTY);
				//generate_mid_code(37,CODE_EMPTY,CODE_EMPTY,CODE_EMPTY);
				fprintf(output_file, "This is a loop statement!\n");
				//printf("This is a loop statement!\n");
				return;
			}
			else {
				error(RPAR_ERROR, line);
				do {
					symbol = insymbol();
				} while (symbol != IFSY && symbol != DOSY && symbol != SWISY && symbol != LBRASSY && symbol != IDSY && symbol != SCANSY && symbol != PRISY && symbol != SEMISY && symbol != RTSY);
				return;
			}
		}
		else {
			error(LPAR_ERROR, line);
			do {
				symbol = insymbol();
			} while (symbol != IFSY && symbol != DOSY && symbol != SWISY && symbol != LBRASSY && symbol != IDSY && symbol != SCANSY && symbol != PRISY && symbol != SEMISY && symbol != RTSY);
			return;
		}
	}
	else {
		error(WHILESY_ERROR, line);
		do {
			symbol = insymbol();
		} while (symbol != IFSY && symbol != DOSY && symbol != SWISY && symbol != LBRASSY && symbol != IDSY && symbol != SCANSY && symbol != PRISY && symbol != SEMISY && symbol != RTSY);
		return;
	}
}

void switch_state() {
	char label[100];
	char for_compare[100];       //expr������Ľ��
	generate_label(label);
	symbol = insymbol();
	if (symbol == LPARSY) {
		symbol = insymbol();
		expr();
		strcpy(for_compare, now_result);
		if (symbol == RPARSY) {
			symbol = insymbol();
			if (symbol == LBRASSY) {
				symbol = insymbol();
				situation_list(label, for_compare);
				if (symbol == RBRASSY) {
					symbol = insymbol();
					//generate_mid_code(37,CODE_EMPTY,CODE_EMPTY,CODE_EMPTY);
					generate_mid_code(24, label, CODE_EMPTY, CODE_EMPTY);
					fprintf(output_file, "This is a switch statement!\n");
					//printf("This is a switch statement!\n");
					return;
				}
				else {
					error(RBRAS_ERROR, line);
					do {
						symbol = insymbol();
					} while (symbol != IFSY && symbol != DOSY && symbol != SWISY && symbol != LBRASSY && symbol != IDSY && symbol != SCANSY && symbol != PRISY && symbol != SEMISY && symbol != RTSY);
					return;
				}
			}
			else {
				error(LBRAS_ERROR, line);
				do {
					symbol = insymbol();
				} while (symbol != IFSY && symbol != DOSY && symbol != SWISY && symbol != LBRASSY && symbol != IDSY && symbol != SCANSY && symbol != PRISY && symbol != SEMISY && symbol != RTSY);
				return;
			}
		}
		else {
			error(RPAR_ERROR, line);
			do {
				symbol = insymbol();
			} while (symbol != IFSY && symbol != DOSY && symbol != SWISY && symbol != LBRASSY && symbol != IDSY && symbol != SCANSY && symbol != PRISY && symbol != SEMISY && symbol != RTSY);
			return;
		}
	}
	else {
		error(LPAR_ERROR, line);
		do {
			symbol = insymbol();
		} while (symbol != IFSY && symbol != DOSY && symbol != SWISY && symbol != LBRASSY && symbol != IDSY && symbol != SCANSY && symbol != PRISY && symbol != SEMISY && symbol != RTSY);
		return;
	}
}

void situation_list(char label[], char for_compare[]) {
	do {
		case_state(label, for_compare);
	} while (symbol == CASESY);
	fprintf(output_file, "This is a situation list!\n");
	//printf("This is a situation list!\n");
}

void case_state(char label[], char for_compare[]) {
	char compare_result[100];
	char my_label[100];
	//generate_temp_var(compare_result);
	generate_new_temp_var(compare_result);
	//address = address+1;
	//append_to_table(compare_result,1,1,0,-1,address);
	generate_label(my_label);
	if (symbol == CASESY) {
		symbol = insymbol();
		if (symbol == CHAR2SY) {
			const_value = TOKEN[1];
			sprintf(TEMP, "%d", const_value);
			generate_mid_code(20, for_compare, TEMP, compare_result);
			generate_mid_code(22, compare_result, my_label, CODE_EMPTY);
			//generate_mid_code(37,CODE_EMPTY,CODE_EMPTY,CODE_EMPTY);
			fprintf(output_file, "This is a char!\n");
			//printf("This is a char!\n");
			fprintf(output_file, "This is a constant!\n");
			//printf("This is a constant!\n");
		}
		else if (symbol == PLUSSY || symbol == MINUSSY) {
			symbol = insymbol();
			if (symbol != DIGITSY) {
				error(AFTER_OP_DIGIT_ERROR, line);
				do {
					symbol = insymbol();
				} while (symbol != IFSY && symbol != DOSY && symbol != SWISY && symbol != LBRASSY && symbol != IDSY && symbol != SCANSY && symbol != PRISY && symbol != SEMISY && symbol != RTSY);
				return;
			}
			if (trans_num == 0) {
				error(AFTER_OP_DIGIT_ERROR, line);
				do {
					symbol = insymbol();
				} while (symbol != IFSY && symbol != DOSY && symbol != SWISY && symbol != LBRASSY && symbol != IDSY && symbol != SCANSY && symbol != PRISY && symbol != SEMISY && symbol != RTSY);
				return;
			}
			generate_mid_code(20, for_compare, TOKEN, compare_result);
			generate_mid_code(22, compare_result, my_label, CODE_EMPTY);
			//generate_mid_code(37,CODE_EMPTY,CODE_EMPTY,CODE_EMPTY);
			fprintf(output_file, "This is an integer!\n");
			//printf("This is an integer!\n");
			fprintf(output_file, "This is a constant!\n");
			//printf("This is a constant!\n");
		}
		else if (symbol == DIGITSY) {
			generate_mid_code(20, for_compare, TOKEN, compare_result);
			generate_mid_code(22, compare_result, my_label, CODE_EMPTY);
			//generate_mid_code(37,CODE_EMPTY,CODE_EMPTY,CODE_EMPTY);
			fprintf(output_file, "This is an integer!\n");
			//printf("This is an integer!\n");
			fprintf(output_file, "This is a constant!\n");
			//printf("This is a constant!\n");
		}
		else {
			error(CASE_CONST_ERROR, line);
			do {
				symbol = insymbol();
			} while (symbol != IFSY && symbol != DOSY && symbol != SWISY && symbol != LBRASSY && symbol != IDSY && symbol != SCANSY && symbol != PRISY && symbol != SEMISY && symbol != RTSY);
			return;
		}
		symbol = insymbol();
		if (symbol != COLONSY) {
			error(COLON_ERROR, line);
			do {
				symbol = insymbol();
			} while (symbol != IFSY && symbol != DOSY && symbol != SWISY && symbol != LBRASSY && symbol != IDSY && symbol != SCANSY && symbol != PRISY && symbol != SEMISY && symbol != RTSY);
			return;
		}
		symbol = insymbol();
		state();
		generate_mid_code(33, label, CODE_EMPTY, CODE_EMPTY);
		//generate_mid_code(37,CODE_EMPTY,CODE_EMPTY,CODE_EMPTY);
		generate_mid_code(24, my_label, CODE_EMPTY, CODE_EMPTY);
		fprintf(output_file, "This is a case statement!\n");
		//printf("This is a case statement!\n");
		return;
	}
	else {
		error(CASE_ERROR, line);
		do {
			symbol = insymbol();
		} while (symbol != IFSY && symbol != DOSY && symbol != SWISY && symbol != LBRASSY && symbol != IDSY && symbol != SCANSY && symbol != PRISY && symbol != SEMISY && symbol != RTSY);
		return;
	}
}

void val_fun_call2() {
	int type;
	char my_func_name[100];
	strcpy(my_func_name, TOKEN);           //�������ô����������func_name Ӧ�ò��ᱴ���ģ�
	symbol = insymbol(); //�����ʶ����(�Ѿ�����
	symbol = insymbol();
	val_para_list();
	type = get_func_type(my_func_name);
	if (type != 1 && type != 2) {
		error(FUNC_NO_DEF_ERROR, line);
		do {
			symbol = insymbol();
		} while (symbol != RPARSY);
		symbol = insymbol();
		return;
	}
	if (symbol != RPARSY) {
		error(RPAR_ERROR, line);
		do {
			symbol = insymbol();
		} while (symbol != IFSY && symbol != DOSY && symbol != SWISY && symbol != LBRASSY && symbol != IDSY && symbol != SCANSY && symbol != PRISY && symbol != SEMISY && symbol != RTSY);
		return;
	}
	generate_temp_var(now_result);
	//address = address+1;
	//append_to_table(now_result,1,1,0,-1,address);
	generate_mid_code(14, my_func_name, CODE_EMPTY, now_result);
	if (factor_type == 0) {
		if (type == 1) {
			factor_type = 1;
		}
		else {
			factor_type = 2;
		}
	}
	symbol = insymbol();
	fprintf(output_file, "This is a value function call!\n");
	//printf("This is a value function call!\n");
}

void val_fun_call() {
	int type;
	char my_func_name[100];
	strcpy(my_func_name, TOKEN);           //�������ô����������func_name Ӧ�ò��ᱴ���ģ�
	symbol = insymbol(); //�����ʶ����(�Ѿ�����
	symbol = insymbol();
	val_para_list();
	type = get_func_type(my_func_name);
	if (type != 1 && type != 2) {
		error(FUNC_NO_DEF_ERROR, line);
		do {
			symbol = insymbol();
		} while (symbol != RPARSY);
		symbol = insymbol();
		return;
	}
	if (symbol != RPARSY) {
		error(RPAR_ERROR, line);
		do {
			symbol = insymbol();
		} while (symbol != IFSY && symbol != DOSY && symbol != SWISY && symbol != LBRASSY && symbol != IDSY && symbol != SCANSY && symbol != PRISY && symbol != SEMISY && symbol != RTSY);
		return;
	}
	generate_mid_code(14, my_func_name, CODE_EMPTY, CODE_EMPTY);
	symbol = insymbol();
	fprintf(output_file, "This is a value function call!\n");
	//printf("This is a value function call!\n");
}

void void_fun_call() {
	int type;
	char my_func_name[100];
	strcpy(my_func_name, TOKEN);           //�������ô����������func_name Ӧ�ò��ᱴ���ģ�
	symbol = insymbol(); //�����ʶ����(�Ѿ�����
	symbol = insymbol();
	val_para_list();
	if (symbol != RPARSY) {
		error(RPAR_ERROR, line);
		do {
			symbol = insymbol();
		} while (symbol != IFSY && symbol != DOSY && symbol != SWISY && symbol != LBRASSY && symbol != IDSY && symbol != SCANSY && symbol != PRISY && symbol != SEMISY && symbol != RTSY);
		return;
	}
	type = get_func_type(my_func_name);
	if (type != 0) {
		error(FUNC_NO_DEF_ERROR, line);
		do {
			symbol = insymbol();
		} while (symbol != RPARSY);
		symbol = insymbol();
		return;
	}
	symbol = insymbol();
	generate_mid_code(15, my_func_name, CODE_EMPTY, CODE_EMPTY);
	fprintf(output_file, "This is a void function call!\n");
	//printf("This is a void function call!\n");
}

void val_para_list() {
	para_num = 0;
	do {
		if (symbol == COMMASY) {
			symbol = insymbol();
		}
		if (symbol == PLUSSY || symbol == MINUSSY || symbol == IDSY || symbol == CHAR2SY || symbol == DIGITSY || symbol == LPARSY) {
			expr();
			generate_mid_code(35, now_result, CODE_EMPTY, CODE_EMPTY);
			para_num++;
		}
	} while (symbol == COMMASY);
	fprintf(output_file, "This is a value parameter list!\n");
	//printf("This is a value parameter list!\n");
	return;
}

void assign_state() {
	char src1[100];
	char src2[100];
	char result[100];
	int nothing;
	//char temp[50];
	strcpy(result, TOKEN);
	symbol = insymbol();
	if (symbol == ASSIGNSY) {
		symbol = insymbol();
		expr();
		nothing = index_in_table(result, 0); //����Ҫ�жϣ�1.������ֵ����  2.char��int��ֵ 3.�������帳ֵ
		if (const_flag) {
			error(CONST_ASSIGNMENT_ERROR, line);
			do {
				symbol = insymbol();
			} while (symbol != IFSY && symbol != DOSY && symbol != SWISY && symbol != LBRASSY && symbol != IDSY && symbol != SCANSY && symbol != PRISY && symbol != SEMISY && symbol != RTSY);
			return;
		}
		if (array_flag) {
			error(ARRAY_ASSIGNMENT_ERROR, line);
			do {
				symbol = insymbol();
			} while (symbol != IFSY && symbol != DOSY && symbol != SWISY && symbol != LBRASSY && symbol != IDSY && symbol != SCANSY && symbol != PRISY && symbol != SEMISY && symbol != RTSY);
			return;
		}
		if (nothing == 2 && factor_type == 1) {
			error(CHAR_ASSIGNMENT_ERROR, line);
		}
		strcpy(src1, now_result);
		generate_mid_code(11, src1, CODE_EMPTY, result);
		fprintf(output_file, "This is an assignment statement!\n");
		//printf("This is an assignment statement!\n");
		return;
	}
	else {                     //����Ԫ�ظ�ֵ
		symbol = insymbol();
		expr();
		strcpy(src2, now_result);
		if (symbol != RBRASY) {
			error(RBRA_ERROR, line);
			do {
				symbol = insymbol();
			} while (symbol != IFSY && symbol != DOSY && symbol != SWISY && symbol != LBRASSY && symbol != IDSY && symbol != SCANSY && symbol != PRISY && symbol != SEMISY && symbol != RTSY);
			return;
		}
		symbol = insymbol();
		if (symbol != ASSIGNSY) {
			error(ASSIGN_ERROR, line);
			do {
				symbol = insymbol();
			} while (symbol != IFSY && symbol != DOSY && symbol != SWISY && symbol != LBRASSY && symbol != IDSY && symbol != SCANSY && symbol != PRISY && symbol != SEMISY && symbol != RTSY);
			return;
		}
		symbol = insymbol();
		expr();
		strcpy(src1, now_result);
		generate_mid_code(12, src1, src2, result);
		fprintf(output_file, "This is an assignment statement!\n");
		//printf("This is an assignment statement!\n");
		return;
	}
}

void read_state() {
	char var_name[100];
	int get_index;
	symbol = insymbol();
	if (symbol != LPARSY) {
		error(LPAR_ERROR, line);
		do {
			symbol = insymbol();
		} while (symbol != IFSY && symbol != DOSY && symbol != SWISY && symbol != LBRASSY && symbol != IDSY && symbol != SCANSY && symbol != PRISY && symbol != SEMISY && symbol != RTSY);
		return;
	}
	do {
		symbol = insymbol();
		if (symbol != IDSY) {
			error(ID_ERROR, line);
			do {
				symbol = insymbol();
			} while (symbol != IFSY && symbol != DOSY && symbol != SWISY && symbol != LBRASSY && symbol != IDSY && symbol != SCANSY && symbol != PRISY && symbol != SEMISY && symbol != RTSY);
			return;
		}
		strcpy(var_name, TOKEN);
		get_index = index_in_table(var_name, 0);
		factor_type = get_index;
		if (var_flag == 0) {
			error(READ_ARRAY_ERROR, line);
		}
		if (factor_type == 1) {
			generate_mid_code(27, CODE_INT, CODE_EMPTY, var_name);
		}
		else {
			generate_mid_code(27, CODE_CHAR, CODE_EMPTY, var_name);
		}
		symbol = insymbol();
	} while (symbol == COMMASY);
	if (symbol != RPARSY) {
		error(RPAR_ERROR, line);
		do {
			symbol = insymbol();
		} while (symbol != IFSY && symbol != DOSY && symbol != SWISY && symbol != LBRASSY && symbol != IDSY && symbol != SCANSY && symbol != PRISY && symbol != SEMISY && symbol != RTSY);
		return;
	}
	symbol = insymbol();
	fprintf(output_file, "This is a read statement!\n");
	//printf("This is a read statement!\n");
}

void write_state() {
	char src1[100];
	char src2[100];
	strcpy(src1, CODE_EMPTY);
	strcpy(src2, CODE_EMPTY);
	symbol = insymbol();
	if (symbol != LPARSY) {
		error(LPAR_ERROR, line);
		do {
			symbol = insymbol();
		} while (symbol != IFSY && symbol != DOSY && symbol != SWISY && symbol != LBRASSY && symbol != IDSY && symbol != SCANSY && symbol != PRISY && symbol != SEMISY && symbol != RTSY);
		return;
	}
	symbol = insymbol();
	if (symbol == STRINGSY) {
		strcpy(src1, TOKEN);
		fprintf(output_file, "This is a string!\n");
		//printf("This is a string!\n");
		symbol = insymbol();
		if (symbol == COMMASY) {
			symbol = insymbol();
			expr();
			if (symbol != RPARSY) {
				error(RPAR_ERROR, line);
				do {
					symbol = insymbol();
				} while (symbol != IFSY && symbol != DOSY && symbol != SWISY && symbol != LBRASSY && symbol != IDSY && symbol != SCANSY && symbol != PRISY && symbol != SEMISY && symbol != RTSY);
				return;
			}
			strcpy(src2, now_result);
			symbol = insymbol();
			if (factor_type == 1) {
				generate_mid_code(28, src1, src2, CODE_INT);
			}
			else {
				generate_mid_code(28, src1, src2, CODE_CHAR);
			}
			fprintf(output_file, "This is a write statement!\n");
			//printf("This is a write statement!\n");
			return;
		}
		else if (symbol == RPARSY) {
			symbol = insymbol();
			generate_mid_code(28, src1, src2, CODE_EMPTY);
			fprintf(output_file, "This is a write statement!\n");
			//printf("This is a write statement!\n");
			return;
		}
		else {
			error(RPAR_ERROR, line);
			do {
				symbol = insymbol();
			} while (symbol != IFSY && symbol != DOSY && symbol != SWISY && symbol != LBRASSY && symbol != IDSY && symbol != SCANSY && symbol != PRISY && symbol != SEMISY && symbol != RTSY);
			return;
		}
		//��ʱû��else
	}
	else {
		expr();
		if (symbol != RPARSY) {
			error(RPAR_ERROR, line);
			do {
				symbol = insymbol();
			} while (symbol != IFSY && symbol != DOSY && symbol != SWISY && symbol != LBRASSY && symbol != IDSY && symbol != SCANSY && symbol != PRISY && symbol != SEMISY && symbol != RTSY);
			return;
		}
		strcpy(src2, now_result);
		if (factor_type == 1) {
			generate_mid_code(28, src1, src2, CODE_INT);
		}
		else {
			generate_mid_code(28, src1, src2, CODE_CHAR);
		}
		symbol = insymbol();
		fprintf(output_file, "This is a write statement!\n");
		//printf("This is a write statement!\n");
		return;
	}
}

void return_state() {
	char src[100];
	symbol = insymbol();
	if (symbol == LPARSY) {
		if (void_flag == 1) {
			error(VOID_RT_ERROR, line);
			do {
				symbol = insymbol();
			} while (symbol != SEMISY);
			return;
		}
		rt_flag = 1;
		symbol = insymbol();
		expr();
		strcpy(src, now_result);
		if (symbol != RPARSY) {
			error(RPAR_ERROR, line);
			do {
				symbol = insymbol();
			} while (symbol != IFSY && symbol != DOSY && symbol != SWISY && symbol != LBRASSY && symbol != IDSY && symbol != SCANSY && symbol != PRISY && symbol != SEMISY && symbol != RTSY);
			return;
		}
		generate_mid_code(26, src, CODE_EMPTY, CODE_EMPTY);
		//generate_mid_code(37,CODE_EMPTY,CODE_EMPTY,CODE_EMPTY);
		symbol = insymbol();
		fprintf(output_file, "This is a return statement!\n");
		//printf("This is a return statement!\n");
		return;
	}
	else {
		if (val_flag == 1) {
			error(VAL_RT_ERROR, line);
			do {
				symbol = insymbol();
			} while (symbol != IFSY && symbol != DOSY && symbol != SWISY && symbol != LBRASSY && symbol != IDSY && symbol != SCANSY && symbol != PRISY && symbol != SEMISY && symbol != RTSY);
			return;
		}
		if (main_flag) {
			generate_mid_code(34, CODE_EMPTY, CODE_EMPTY, CODE_EMPTY);
			//generate_mid_code(37,CODE_EMPTY,CODE_EMPTY,CODE_EMPTY);
		}
		else {
			generate_mid_code(25, CODE_EMPTY, CODE_EMPTY, CODE_EMPTY);
			//generate_mid_code(37,CODE_EMPTY,CODE_EMPTY,CODE_EMPTY);
		}
		fprintf(output_file, "This is a return statement!\n");
		//printf("This is a return statement!\n");
		return;
	}
}

void expr() {
	factor_type = 0;
	char src1[100];
	char src2[100];
	char result[100];
	if (symbol == PLUSSY || symbol == MINUSSY) {
		factor_type = 1;
		if (symbol == PLUSSY) {
			symbol = insymbol();
			term();
			strcpy(result, now_result);
		}
		else {
			symbol = insymbol();
			term();
			strcpy(src2, now_result);
			generate_temp_var(result);
			//address = address+1;
			//append_to_table(result,1,1,0,-1,address);
			generate_mid_code(30, CODE_ZERO, src2, result);
		}
		while (symbol == PLUSSY || symbol == MINUSSY) {
			factor_type = 1;
			strcpy(src1, result);
			generate_temp_var(result);
			//address = address+1;
			//append_to_table(result,1,1,0,-1,address);
			if (symbol == PLUSSY) {                   //Ĭ���õ���ͬһ����ʱ�����洢��
				symbol = insymbol();
				term();
				strcpy(src2, now_result);
				generate_mid_code(29, src1, src2, result);
			}
			else {
				symbol = insymbol();
				term();
				strcpy(src2, now_result);
				generate_mid_code(30, src1, src2, result);
			}
		}
	}
	else {
		term();
		strcpy(result, now_result);
		while (symbol == PLUSSY || symbol == MINUSSY) {
			factor_type = 1;
			strcpy(src1, result);
			generate_temp_var(result);
			//address = address+1;
			//append_to_table(result,1,1,0,-1,address);
			if (symbol == PLUSSY) {                   //Ĭ���õ���ͬһ����ʱ�����洢��
				symbol = insymbol();
				term();
				strcpy(src2, now_result);
				generate_mid_code(29, src1, src2, result);
			}
			else {
				symbol = insymbol();
				term();
				strcpy(src2, now_result);
				generate_mid_code(30, src1, src2, result);
			}
		}
	}
	strcpy(now_result, result);
	fprintf(output_file, "This is an expression!\n");
	//printf("This is an expression!\n");
}

void term() {
	char src1[100];
	char src2[100];
	char result[100];
	factor();
	strcpy(result, now_result);
	while (symbol == STARSY || symbol == DIVSY) {
		strcpy(src1, result);
		generate_temp_var(result);
		//address = address+1;
		//append_to_table(result,1,1,0,-1,address);
		if (symbol == STARSY) {
			symbol = insymbol();
			factor();
			strcpy(src2, now_result);
			generate_mid_code(31, src1, src2, result);
		}
		else {
			symbol = insymbol();
			factor();
			strcpy(src2, now_result);
			generate_mid_code(32, src1, src2, result);
		}

	}
	strcpy(now_result, result);
	fprintf(output_file, "This is a term!\n");
	//printf("This is a term!\n");
}

void factor() {
	char result[100];
	char id_record[100];
	int temp_type;
	int sign;
	strcpy(result, CODE_EMPTY);
	if (symbol == IDSY) {
		strcpy(id_record, TOKEN);
		//�����ֳ���
		pre_ch = CHAR;                            //�����ֳ�
		pre_line_index = index_in_line;
		pre_symbol = symbol;
		strcpy(PRETOKEN, TOKEN);
		symbol = insymbol();
		if (symbol == LBRASY) {
			symbol = insymbol();
			temp_type = factor_type;
			expr();
			factor_type = temp_type;
			if (symbol != RBRASY) {
				error(RBRA_ERROR, line);
				do {
					symbol = insymbol();
				} while (symbol != SEMISY && symbol != ASSIGNSY && symbol != PLUSSY && symbol != MINUSSY && symbol != STARSY && symbol != DIVSY && symbol != RPARSY && symbol != COMMASY && symbol != LTSY && symbol != LESY && symbol != GTRSY && symbol != GTESY && symbol != EQUSY && symbol != NEQSY);
				return;
			}
			//����ط�Ӧ����Ҫ�������Ƿ���ڵ�
			temp_type = index_in_table(id_record, 0);
			if (array_flag == 0) {
				error(ID_NO_DEF_ERROR, line);
				do {
					symbol = insymbol();
				} while (symbol != SEMISY && symbol != ASSIGNSY && symbol != PLUSSY && symbol != MINUSSY && symbol != STARSY && symbol != DIVSY && symbol != RPARSY && symbol != COMMASY && symbol != LTSY && symbol != LESY && symbol != GTRSY && symbol != GTESY && symbol != EQUSY && symbol != NEQSY);
				return;
			}
			if (factor_type == 0) {
				factor_type = temp_type;
			}
			strcpy(result, now_result);
			generate_temp_var(now_result);
			//address = address+1;
			//append_to_table(now_result,1,1,0,-1,address);
			generate_mid_code(36, id_record, result, now_result);
			symbol = insymbol();
			fprintf(output_file, "This is a factor!\n");
			//printf("This is a factor!\n");
			return;
		}
		else if (symbol == LPARSY) {
			strcpy(TOKEN, PRETOKEN);               //�ָ��ֳ�
			CHAR = pre_ch;
			index_in_line = pre_line_index;
			symbol = pre_symbol;
			val_fun_call2();
			fprintf(output_file, "This is a factor!\n");
			//printf("This is a factor!\n");
			return;
		}
		else {
			if (factor_type == 0) {
				factor_type = index_in_table(id_record, 0);
			}
			temp_type = index_in_table(id_record, 0);
			if (const_flag == 1) {
				temp_type = get_const_value(id_record);
				sprintf(now_result, "%d", temp_type);
				const_flag = 0;
			}
			else {
				strcpy(now_result, id_record);
			}
			fprintf(output_file, "This is a factor!\n");
			//printf("This is a factor!\n");
			return;
		}
	}
	else if (symbol == CHAR2SY) {
		if (factor_type == 0) {
			factor_type = 2;
		}
		const_value = TOKEN[1];
		sprintf(now_result, "%d", const_value);
		symbol = insymbol();
		fprintf(output_file, "This is a char!\n");
		//printf("This is a char!\n");
		fprintf(output_file, "This is a factor!\n");
		//printf("This is a factor!\n");
		return;
	}
	else if (symbol == PLUSSY || symbol == MINUSSY) {
		if (symbol == PLUSSY) {
			sign = 1;
		}
		else {
			sign = -1;
		}
		symbol = insymbol();
		if (symbol != DIGITSY) {
			error(AFTER_OP_DIGIT_ERROR, line);
			do {
				symbol = insymbol();
			} while (symbol != SEMISY && symbol != ASSIGNSY && symbol != PLUSSY && symbol != MINUSSY && symbol != STARSY && symbol != DIVSY && symbol != RPARSY && symbol != COMMASY && symbol != LTSY && symbol != LESY && symbol != GTRSY && symbol != GTESY && symbol != EQUSY && symbol != NEQSY);
			return;
		}
		if (trans_num == 0) {
			error(AFTER_OP_DIGIT_ERROR, line);
			do {
				symbol = insymbol();
			} while (symbol != SEMISY && symbol != ASSIGNSY && symbol != PLUSSY && symbol != MINUSSY && symbol != STARSY && symbol != DIVSY && symbol != RPARSY && symbol != COMMASY && symbol != LTSY && symbol != LESY && symbol != GTRSY && symbol != GTESY && symbol != EQUSY && symbol != NEQSY);
			return;
		}
		trans_num = sign * trans_num;
		sprintf(now_result, "%ld", trans_num);
		factor_type = 1;
		symbol = insymbol();
		fprintf(output_file, "This is an integer!\n");
		//printf("This is an integer!\n");
		fprintf(output_file, "This is a factor!\n");
		//printf("This is a factor!\n");
		return;
	}
	else if (symbol == DIGITSY) {
		sprintf(now_result, "%ld", trans_num);
		factor_type = 1;
		symbol = insymbol();
		fprintf(output_file, "This is an integer!\n");
		//printf("This is an integer!\n");
		fprintf(output_file, "This is a factor!\n");
		//printf("This is a factor!\n");
		return;
	}
	else if (symbol == LPARSY) {
		symbol = insymbol();
		expr();
		if (symbol != RPARSY) {
			error(RPAR_ERROR, line);
			do {
				symbol = insymbol();
			} while (symbol != SEMISY && symbol != ASSIGNSY && symbol != PLUSSY && symbol != MINUSSY && symbol != STARSY && symbol != DIVSY && symbol != RPARSY && symbol != COMMASY && symbol != LTSY && symbol != LESY && symbol != GTRSY && symbol != GTESY && symbol != EQUSY && symbol != NEQSY);
			return;
		}
		symbol = insymbol();
		fprintf(output_file, "This is a factor!\n");
		//printf("This is a factor!\n");
		return;
	}
	else {
		error(FACTOR_ERROR, line);
		do {
			symbol = insymbol();
		} while (symbol != SEMISY && symbol != ASSIGNSY && symbol != PLUSSY && symbol != MINUSSY && symbol != STARSY && symbol != DIVSY && symbol != RPARSY && symbol != COMMASY && symbol != LTSY && symbol != LESY && symbol != GTRSY && symbol != GTESY && symbol != EQUSY && symbol != NEQSY);
		return;
	}
}



//error.c   Ψһһ����������������Ľ������ӡ���������͵���ʾ
void error(int error_type, int line_index) {
	switch (error_type) {
	case 1: {
		fprintf(output_file, "line %d : non-zero integer shouldn't start with 0'\n", line_index);
		printf("line %d : non-zero integer shouldn't start with 0'\n", line_index);
		break;
	}
	case 2: {
		fprintf(output_file, "line %d : invalid char being declared\n", line_index);
		printf("line %d : invalid char being declared\n", line_index);
		break;
	}
	case 3: {
		fprintf(output_file, "line %d : single quatation don't match\n", line_index);
		printf("line %d : single quatation don't match\n", line_index);
		break;
	}
	case 4: {
		fprintf(output_file, "line %d : double quatation don't match\n", line_index);
		printf("line %d : double quatation don't match\n", line_index);
		break;
	}
	case 5: {
		fprintf(output_file, "line %d : invalid char appears\n", line_index);
		printf("line %d : invalid char appears\n", line_index);
		break;
	}
	case 6: {
		fprintf(output_file, "line %d : integer out of the range\n", line_index);
		printf("line %d : integer out of the range\n", line_index);
		break;
	}
	case 7: {
		fprintf(output_file, "line %d : table overflow!\n", line_index);
		printf("line %d : table overflow!\n", line_index);
		break;
	}
	case 8: {
		fprintf(output_file, "line %d: the parameter number doesn't match!\n", line_index);
		printf("line %d: the parameter number doesn't match!\n", line_index);
		break;
	}
	case 9: {
		fprintf(output_file, "line %d: this function name already exists!\n", line_index);
		printf("line %d: this function name already exists!\n", line_index);
		break;
	}
	case 10: {
		fprintf(output_file, "line %d: this variable name already exists!\n", line_index);
		printf("line %d: this variable name already exists!\n", line_index);
		break;
	}
	case 11: {
		fprintf(output_file, "line %d: this place should be an Identifier after type identifier!\n", line_index);
		printf("line %d: this place should be an Identifier after type identifier!\n", line_index);
		break;
	}
	case 12: {
		fprintf(output_file, "line %d: this place should be an equal in constant defination!\n", line_index);
		printf("line %d: this place should be an equal in constant defination!\n", line_index);
		break;
	}
	case 13: {
		fprintf(output_file, "line %d: the type doesn't match in cosntant defination!\n", line_index);
		printf("line %d: the type doesn't match in cosntant defination!\n", line_index);
		break;
	}
	case 14: {
		fprintf(output_file, "line %d: the type identifier is wrong in cosntant defination!\n", line_index);
		printf("line %d: the type identifier is wrong in cosntant defination!\n", line_index);
		break;
	}
	case 15: {
		fprintf(output_file, "line %d: this place should be a semicolon!\n", line_index);
		printf("line %d: this place should be a semicolon!\n", line_index);
		break;
	}
	case 16: {
		fprintf(output_file, "line %d: the index of array is not unsigned integer in variable defination!\n", line_index);
		printf("line %d: the index of array is not unsigned integer in variable defination!\n", line_index);
		break;
	}
	case 17: {
		fprintf(output_file, "line %d: this place should be a right parenthese!\n", line_index);
		printf("line %d: this place should be a right parenthese!\n", line_index);
		break;
	}
	case 18: {
		fprintf(output_file, "line %d: this place should be a right bracket!\n", line_index);
		printf("line %d: this place should be a right bracket!\n", line_index);
		break;
	}
	case 19: {
		fprintf(output_file, "line %d: this place should be a right brace!\n", line_index);
		printf("line %d: this place should be a right brace!\n", line_index);
		break;
	}
	case 20: {
		fprintf(output_file, "line %d: the identifier is not a variable in read statement!\n", line_index);
		printf("line %d: the identifier is not a variable in read statement!\n", line_index);
		break;
	}
	case 21: {
		fprintf(output_file, "line %d: this place should be the key word main!\n", line_index);
		printf("line %d: this place should be the key word main!\n", line_index);
		break;
	}
	case 22: {
		fprintf(output_file, "line %d: this place should be a left parenthese!\n", line_index);
		printf("line %d: this place should be a left parenthese!\n", line_index);
		break;
	}
	case 23: {
		fprintf(output_file, "line %d: this place should be a left brace!\n", line_index);
		printf("line %d: this place should be a left brace!\n", line_index);
		break;
	}
	case 24: {
		fprintf(output_file, "line %d: there should be an unsigned integer after + or -!\n", line_index);
		printf("line %d: there should be an unsigned integer after + or -!\n", line_index);
		break;
	}
	case 25: {
		fprintf(output_file, "line %d: there should be a factor here!\n", line_index);
		printf("line %d: there should be a factor here!\n", line_index);
		break;
	}
	case 26: {
		fprintf(output_file, "line %d: there should be a left parenthese or a left bracket or a left brace after identifier!\n", line_index);
		printf("line %d: there should be a left parenthese or a left bracket or a left brace after identifier!\n", line_index);
		break;
	}
	case 27: {
		fprintf(output_file, "line %d: wrong relational operater!\n", line_index);
		printf("line %d: wrong relational operater!\n", line_index);
		break;
	}
	case 28: {
		fprintf(output_file, "line %d: this place should be the key word while!\n", line_index);
		printf("line %d: this place should be the key word while!\n", line_index);
		break;
	}
	case 29: {
		fprintf(output_file, "line %d: array or const is not allowed to appear in read statement!\n", line_index);
		printf("line %d: array or const is not allowed to appear in read statement!\n", line_index);
		break;
	}
	case 30: {
		fprintf(output_file, "line %d: in void function, should not return value!\n", line_index);
		printf("line %d: in void function, should not return value!\n", line_index);
		break;
	}
	case 31: {
		fprintf(output_file, "line %d: in int or char function, should return value!\n", line_index);
		printf("line %d: in int or char function, should return value!\n", line_index);
		break;
	}
	case 32: {
		fprintf(output_file, "line %d: there should be void before the key word main!\n", line_index);
		printf("line %d: there should be void before the key word main!\n", line_index);
		break;
	}
	case 33: {
		fprintf(output_file, "line %d: mistake after identifier in identifier declararion!\n", line_index);
		printf("line %d: mistake after identifier in identifier declararion!\n", line_index);
		break;
	}
	case 34: {
		fprintf(output_file, "line %d: in int or char function, should have return statement!\n", line_index);
		printf("line %d: in int or char function, should have return statement!\n", line_index);
		break;
	}
	case 35: {
		fprintf(output_file, "line %d: this place should be the key word case!\n", line_index);
		printf("line %d: this place should be the key word case!\n", line_index);
		break;
	}
	case 36: {
		fprintf(output_file, "line %d: this place should be a constant after case!\n", line_index);
		printf("line %d: this place should be a constant after case!\n", line_index);
		break;
	}
	case 37: {
		fprintf(output_file, "line %d: this place should be a colon!\n", line_index);
		printf("line %d: this place should be a colon!\n", line_index);
		break;
	}
	case 38: {
		fprintf(output_file, "line %d: this place should be an equal!\n", line_index);
		printf("line %d: this place should be an equal!\n", line_index);
		break;
	}
	case 39: {
		fprintf(output_file, "line %d: undefined function call or the num of value para is not equal to defined para or the type is wrong!\n", line_index);
		printf("line %d: undefined function call or the num of value para is not equal to defined para or the type is wrong!\n", line_index);
		break;
	}
	case 40: {
		fprintf(output_file, "line %d: undefined identifier or wrong type!\n", line_index);
		printf("line %d: undefined identifier or wrong type!\n", line_index);
		break;
	}
	case 41: {
		fprintf(output_file, "line %d: mid_code out of index!\n", line_index);
		printf("line %d: mid_code out of index!\n", line_index);
		break;
	}
	case 42: {
		fprintf(output_file, "line %d: constant can't be assigned!\n", line_index);
		printf("line %d: constant can't be assigned!\n", line_index);
		break;
	}
	case 43: {
		fprintf(output_file, "line %d: array's name can't be assigned!\n", line_index);
		printf("line %d: array's name can't be assigned!\n", line_index);
		break;
	}
	case 44: {
		fprintf(output_file, "line %d: char shouldn't be assigned by int!(warning)\n", line_index);
		printf("line %d: char shouldn't be assigned by int!(warning)\n", line_index);
		break;
	}
	case 45: {
		fprintf(output_file, "line %d: function block out of range(optimizer)\n", line_index);
		printf("line %d: function block out of range(optimizer)\n", line_index);
		break;
	}
	case 46: {
		fprintf(output_file, "line %d: basic block out of range(optimizer)\n", line_index);
		printf("line %d: basic block out of range(optimizer)\n", line_index);
		break;
	}
	case 47: {
		fprintf(output_file, "line %d: num of node out of range(optimizer)\n", line_index);
		printf("line %d: num of node out of range(optimizer)\n", line_index);
		break;
	}
	case 48: {
		fprintf(output_file, "line %d: num of var one node out of range(optimizer)\n", line_index);
		printf("line %d: num of var one node out of range(optimizer)\n", line_index);
		break;
	}
	}
	//fclose(output_file);
	return;
}


//wordtest.c

int get_ch() {
	if (index_in_line == line_lenth) {
		//index_in_line��ʼΪ0��line_lenth��ʼΪ0���˴���Ϊһ���Ѿ�������ͷ
		line++;
		if (fgets(read_line, 512, compile_file) != NULL) {   //compile_file�ж�ȡһ�л�512���ַ���read_line��Ϊ��������
			line_lenth = strlen(read_line);    //��ȡ��һ�еĳ���
			index_in_line = 0;     //���λ�ô�0��ʼ
			return('\n');                                         //�൱�ڶ�������ĩβ�Ļس�
		}
		else
			return(EOF);
	}
	else {
		index_in_line += 1;
		return(read_line[index_in_line - 1]);//����һ���ֽ�
	}
}

void translate(int sym_num) {
	switch (sym_num) {
	case CONSY: {
		strcpy(out_symbol, "CONSY");
		break;
	}
	case INTSY: {
		strcpy(out_symbol, "INTSY");
		break;
	}
	case CHARSY: {
		strcpy(out_symbol, "CHARSY");
		break;
	}
	case VOIDSY: {
		strcpy(out_symbol, "VOIDSY");
		break;
	}
	case MAINSY: {
		strcpy(out_symbol, "MAINSY");
		break;
	}
	case DOSY: {
		strcpy(out_symbol, "DOSY");
		break;
	}
	case WHISY: {
		strcpy(out_symbol, "WHISY");
		break;
	}
	case SWISY: {
		strcpy(out_symbol, "SWISY");
		break;
	}
	case CASESY: {
		strcpy(out_symbol, "CASESY");
		break;
	}
	case IFSY: {
		strcpy(out_symbol, "IFSY");
		break;
	}
	case SCANSY: {
		strcpy(out_symbol, "SCANSY");
		break;
	}
	case PRISY: {
		strcpy(out_symbol, "PRISY");
		break;
	}
	case RTSY: {
		strcpy(out_symbol, "RTSY");
		break;
	}
	case IDSY: {
		strcpy(out_symbol, "IDSY");
		break;
	}
	case PLUSSY: {
		strcpy(out_symbol, "PLUSSY");
		break;
	}
	case MINUSSY: {
		strcpy(out_symbol, "MINUSSY");
		break;
	}
	case STARSY: {
		strcpy(out_symbol, "STARSY");
		break;
	}
	case DIVSY: {
		strcpy(out_symbol, "DIVSY");
		break;
	}
	case COMMASY: {
		strcpy(out_symbol, "COMMASY");
		break;
	}
	case COLONSY: {
		strcpy(out_symbol, "COLONSY");
		break;
	}
	case LPARSY: {
		strcpy(out_symbol, "LPARSY");
		break;
	}
	case RPARSY: {
		strcpy(out_symbol, "RPARSY");
		break;
	}
	case LBRASY: {
		strcpy(out_symbol, "LBRASY");
		break;
	}
	case RBRASY: {
		strcpy(out_symbol, "RBRASY");
		break;
	}
	case LBRASSY: {
		strcpy(out_symbol, "LBRASSY");
		break;
	}
	case RBRASSY: {
		strcpy(out_symbol, "RBRASSY");
		break;
	}
	case ASSIGNSY: {
		strcpy(out_symbol, "ASSIGNSY");
		break;
	}
	case EQUSY: {
		strcpy(out_symbol, "EQUSY");
		break;
	}
	case GTRSY: {
		strcpy(out_symbol, "GTRSY");
		break;
	}
	case GTESY: {
		strcpy(out_symbol, "GTESY");
		break;
	}
	case LTSY: {
		strcpy(out_symbol, "LTSY");
		break;
	}
	case LESY: {
		strcpy(out_symbol, "LESY");
		break;
	}
	case NEQSY: {
		strcpy(out_symbol, "NEQSY");
		break;
	}
	case DIGITSY: {
		strcpy(out_symbol, "DIGITSY");
		break;
	}
	case CHAR2SY: {
		strcpy(out_symbol, "CHAR2SY");
		break;
	}
	case STRINGSY: {
		strcpy(out_symbol, "STRINGSY");
		break;
	}
	case SEMISY: {
		strcpy(out_symbol, "SEMISY");
		break;
	}

	}
}



void reset_token() {               //Ϊ��һ�ζ��뵥����׼��
	int i;
	for (i = 0; i < 100; i++)
		TOKEN[i] = '\0';
	return;
}

int trans_to_num() {               //�������ַ���ת��Ϊ����
	int len, i;
	long long result;
	len = strlen(TOKEN);
	result = 0;
	for (i = 0; i < len; i++) {
		result = result * 10 + TOKEN[i] - '0';
		if (result > imax) {
			error(OUT_OF_BOUND_ERROR, line);
			return 0;
		}
	}
	return result;
}

void cat(char c) {
	int i = 0;
	while (TOKEN[i] != '\0') {
		i++;
		if (i == 99) {
			printf("too long words\n");
			return;
		}
	}
	TOKEN[i] = c;
}
//����һ�����ַ�����TOKEN�����в����ж��Ƿ�Խ��
int is_letter() {
	return (isalpha(CHAR) || (CHAR == '_'));
}
//isalpha()������C�������ú����ж��ǲ�����ĸ�ַ�

int is_digit() {
	return isdigit(CHAR);
}
//����Ƿ�ʮ��������

int is_colon() {
	if (CHAR == ':')
		return 1;
	return 0;
}
//����Ƿ�':'

int is_semi() {
	if (CHAR == ';')
		return 1;
	return 0;
}
//����Ƿ�ֺ�
int is_comma() {
	if (CHAR == ',')
		return 1;
	return 0;
}
//��ⶺ��
int is_plus() {
	if (CHAR == '+')
		return 1;
	return 0;
}

int is_minus() {
	if (CHAR == '-')
		return 1;
	return 0;
}

int is_star() {
	if (CHAR == '*')
		return 1;
	return 0;
}

int is_div() {
	if (CHAR == '/')
		return 1;
	return 0;
}

int is_squo() {
	if (CHAR == '\'')
		return 1;
	return 0;
}
//����Ƿ�'\'��б��
int is_dquo() {
	if (CHAR == '\"')
		return 1;
	return 0;
}
//����Ƿ�'\"'˫�����ַ�
int is_lparent() {
	if (CHAR == '\(')
		return 1;
	return 0;
}
//��С����
int is_rparent() {
	if (CHAR == ')')
		return 1;
	return 0;
}
//��С����
int is_lbracket() {
	if (CHAR == '[')
		return 1;
	return 0;
}
//��������
int is_rbracket() {
	if (CHAR == ']')
		return 1;
	return 0;
}
//��������
int is_lbrace() {
	if (CHAR == '{')
		return 1;
	return 0;
}
//�������
int is_rbrace() {
	if (CHAR == '}')
		return 1;
	return 0;
}
//�Ҵ�����
int is_gtr() {
	if (CHAR == '>')
		return 1;
	return 0;
}
//����
int is_lt() {
	if (CHAR == '<')
		return 1;
	return 0;
}
//С��
int is_equ() {
	if (CHAR == '=')
		return 1;
	return 0;
}
//����
int is_exc() {
	if (CHAR == '!')
		return 1;
	return 0;
}
//��̾
int is_zero() {
	if (CHAR == '0')
		return 1;
	return 0;
}
//��0
int is_valid_character() {
	if (CHAR == 32)
		return 1;
	else if (CHAR == 33)
		return 1;
	else if ((CHAR >= 35) && (CHAR <= 126))
		return 1;
	else
		return 0;
}//����ʾ�ַ�

int is_key() {
	if (strcmp(TOKEN, CON) == 0)
		return CONSY;
	else if (strcmp(TOKEN, INT) == 0)
		return INTSY;
	else if (strcmp(TOKEN, _CHAR) == 0)
		return CHARSY;
	else if (strcmp(TOKEN, VOID) == 0)
		return VOIDSY;
	else if (strcmp(TOKEN, MAIN) == 0)
		return MAINSY;
	else if (strcmp(TOKEN, DO) == 0)
		return DOSY;
	else if (strcmp(TOKEN, WHILE) == 0)
		return WHISY;
	else if (strcmp(TOKEN, SWITCH) == 0)
		return SWISY;
	else if (strcmp(TOKEN, CASE) == 0)
		return CASESY;
	else if (strcmp(TOKEN, IF) == 0)
		return IFSY;
	else if (strcmp(TOKEN, SCANF) == 0)
		return SCANSY;
	else if (strcmp(TOKEN, PRINTF) == 0)
		return PRISY;
	else if (strcmp(TOKEN, RETURN) == 0)
		return RTSY;
	else
		return 0;
}
//�ж��Ƕ����ֻ�����ͨ��ʶ��(����0)

//�ж��Ƿ��ʶ��
int insymbol() {
	int symbol;
	int zero_flag = 0;
	reset_token();  //token����ȫ�ÿ�
	while ((CHAR == ' ') || (CHAR == '\t') || (CHAR == '\n')) {   //�൱��Ԥ�����ո���TAB����
		CHAR = get_ch();
		if (CHAR == EOF)           //�ļ�ĩβ����ΪEOF
		{
			printf("end of the file\n");
			fprintf(output_file, "end of the file\n");  //�������˵�����Ѿ�ʵ����ȫ�ı���
			//fclose(compile_file);
			//fclose(output_file);
			//print_mid_code();
			exit(0);
			return -2;
		}
	}
	if (is_letter()) {
		do {
			if (isupper(CHAR))  //�ж��Ƿ��д�ַ�
				cat(tolower(CHAR));//ת����Сд�ַ�����д���token������
			else
				cat(CHAR);
			CHAR = get_ch();   //Ȼ�������µ��ַ�
		} while (is_letter() || is_digit());   //ֻ�л�����ĸ����_�������֣��ӿ��Լ�������
		symbol = is_key();
		if (symbol == 0)
			symbol = IDSY;
	}
	else if (is_digit()) {
		if (is_zero()) {
			zero_flag = 1;
		}
		do {
			cat(CHAR);
			CHAR = get_ch();
		} while (is_digit()); //����0���治��ֱ�Ӹ�����������
		symbol = DIGITSY;
		trans_num = trans_to_num();   //�����Ƿ��ؾ�������ֶ��Ҳ�Ӧ����0
		if ((zero_flag == 1) && (trans_num != 0)) {
			error(ZERO_START_ERROR, line);
		}
	}
	else if (is_plus()) {
		cat(CHAR);
		CHAR = get_ch();
		symbol = PLUSSY;
	}
	else if (is_minus()) {
		cat(CHAR);
		CHAR = get_ch();
		symbol = MINUSSY;
	}
	else if (is_star()) {
		cat(CHAR);
		CHAR = get_ch();
		symbol = STARSY;
	}
	else if (is_div()) {
		cat(CHAR);
		CHAR = get_ch();
		symbol = DIVSY;
	}
	else if (is_gtr()) {
		cat(CHAR);
		CHAR = get_ch();
		if (is_equ()) {
			cat(CHAR);
			symbol = GTESY;
			CHAR = get_ch();
		}
		else
			symbol = GTRSY;
	}
	else if (is_lt()) {
		cat(CHAR);
		CHAR = get_ch();
		if (is_equ()) {
			cat(CHAR);
			symbol = LESY;
			CHAR = get_ch();
		}
		else
			symbol = LTSY;
	}
	else if (is_equ()) {
		cat(CHAR);
		CHAR = get_ch();
		if (is_equ()) {
			cat(CHAR);
			symbol = EQUSY;
			CHAR = get_ch();
		}
		else
			symbol = ASSIGNSY;
	}
	else if (is_exc()) {
		cat(CHAR);
		CHAR = get_ch();
		if (is_equ()) {
			cat(CHAR);
			symbol = NEQSY;
			CHAR = get_ch();
		}
		else {
			error(INVALID_CHARACTER_ERROR, line);
			symbol = -1;                           //������ô����
		}
	}
	else if (is_lparent()) {
		cat(CHAR);
		CHAR = get_ch();
		symbol = LPARSY;
	}
	else if (is_rparent()) {
		cat(CHAR);
		CHAR = get_ch();
		symbol = RPARSY;
	}
	else if (is_lbracket()) {
		cat(CHAR);
		CHAR = get_ch();
		symbol = LBRASY;
	}
	else if (is_rbracket()) {
		cat(CHAR);
		CHAR = get_ch();
		symbol = RBRASY;
	}
	else if (is_lbrace()) {
		cat(CHAR);
		CHAR = get_ch();
		symbol = LBRASSY;
	}
	else if (is_rbrace()) {
		cat(CHAR);
		CHAR = get_ch();
		symbol = RBRASSY;
	}
	else if (is_comma()) {
		cat(CHAR);
		CHAR = get_ch();
		symbol = COMMASY;
	}
	else if (is_colon()) {
		cat(CHAR);
		CHAR = get_ch();
		symbol = COLONSY;
	}
	else if (is_semi()) {
		cat(CHAR);
		CHAR = get_ch();
		symbol = SEMISY;
	}
	else if (is_squo()) {
		cat(CHAR);
		CHAR = get_ch();
		if (is_plus() || is_minus() || is_star() || is_div() || is_letter() || is_digit()) {
			cat(CHAR);
		}
		else {
			error(INVALID_CHAR_ERROR, line);
		}
		CHAR = get_ch();
		if (is_squo()) {
			cat(CHAR);
			CHAR = get_ch();
			symbol = CHAR2SY;
		}
		else {
			error(NO_MATCH_SQ_ERROR, line);
			CHAR = get_ch();
			symbol = -1;
		}
	}
	else if (is_dquo()) {
		cat(CHAR);
		CHAR = get_ch();
		while (is_valid_character()) {
			if (CHAR == '\\')
				cat(CHAR);
			cat(CHAR);
			CHAR = get_ch();
		}
		if (is_dquo()) {
			cat(CHAR);
			CHAR = get_ch();
			symbol = STRINGSY;
		}
		else {
			error(NO_MATCH_DQ_ERROR, line);
			symbol = STRINGSY;
		}
	}
	else {
		symbol = -1;
		error(INVALID_CHARACTER_ERROR, line);
	}
	return symbol;
}


//mid_code.c
//��������ʵ��
void init_code_list() {
	CODE_LIST.code_num = 0;
}

void init_var_num() {
	var_num = 0;
}

void generate_mid_code(int op, char src1[], char src2[], char result[]) {     //������Ҫ������һ����ֵ������
	int index;
	if (CODE_LIST.code_num >= MAX_MID_CODE) {      //�м������̫���򱨴�
		error(OUT_OF_CODE_ERROR, line);
		fclose(compile_file);
		fclose(output_file);
		exit(-1);
		return;
	}
	index = CODE_LIST.code_num;
	CODE_LIST.MID_CODE[index].op = op;
	strcpy(CODE_LIST.MID_CODE[index].src1, src1);
	strcpy(CODE_LIST.MID_CODE[index].src2, src2);
	strcpy(CODE_LIST.MID_CODE[index].result, result);
	CODE_LIST.MID_CODE[index].is_effective = 1;
	CODE_LIST.code_num++;
}

void generate_label(char label[]) {
	sprintf(label, "LABEL%d", label_num);
	label_num++;
	return;
}

void generate_temp_var(char var[]) {
	sprintf(var, "$VAR%d", var_num);
	var_num++;
	return;
}

void generate_new_temp_var(char var[]) {
	sprintf(var, "$S%d", new_var_num);
	new_var_num++;
	return;
}
void print_mid_code() {
	int i;
	mid_code_file = fopen("mid_code.txt", "w");
	for (i = 0; i < CODE_LIST.code_num; i++) {
		if (CODE_LIST.MID_CODE[i].is_effective == 1) {
			print_one_code(i, mid_code_file);
		}
	}
	fclose(mid_code_file);
}


void print_one_code(int number, FILE* mid_code_file) {
	int op_type;
	op_type = CODE_LIST.MID_CODE[number].op;
	switch (op_type) {
	case 1: {
		fprintf(mid_code_file, "CONST INT %s %s\n", CODE_LIST.MID_CODE[number].src1, CODE_LIST.MID_CODE[number].src2);
		break;
	}
	case 2: {
		fprintf(mid_code_file, "CONST CHAR %s %s\n", CODE_LIST.MID_CODE[number].src1, CODE_LIST.MID_CODE[number].src2);
		break;
	}
	case 3: {
		fprintf(mid_code_file, "INT %s\n", CODE_LIST.MID_CODE[number].src1);
		break;
	}
	case 4: {
		fprintf(mid_code_file, "CHAR %s\n", CODE_LIST.MID_CODE[number].src1);
		break;
	}
	case 5: {
		fprintf(mid_code_file, "ARRAY INT %s %s\n", CODE_LIST.MID_CODE[number].src1, CODE_LIST.MID_CODE[number].src2);
		break;
	}
	case 6: {
		fprintf(mid_code_file, "ARRAY CHAR %s %s\n", CODE_LIST.MID_CODE[number].src1, CODE_LIST.MID_CODE[number].src2);
		break;
	}
	case 7: {
		fprintf(mid_code_file, "FUNC INT %s\n", CODE_LIST.MID_CODE[number].src1);
		break;
	}
	case 8: {
		fprintf(mid_code_file, "FUNC CHAR %s\n", CODE_LIST.MID_CODE[number].src1);
		break;
	}
	case 9: {
		fprintf(mid_code_file, "FUNC VOID %s\n", CODE_LIST.MID_CODE[number].src1);
		break;
	}
	case 10: {
		fprintf(mid_code_file, "PARA %s %s\n", CODE_LIST.MID_CODE[number].src2, CODE_LIST.MID_CODE[number].src1);
		break;
	}
	case 11: {
		fprintf(mid_code_file, "%s = %s\n", CODE_LIST.MID_CODE[number].result, CODE_LIST.MID_CODE[number].src1);
		break;
	}
	case 12: {
		fprintf(mid_code_file, "%s[%s] = %s\n", CODE_LIST.MID_CODE[number].result, CODE_LIST.MID_CODE[number].src2, CODE_LIST.MID_CODE[number].src1);
		break;
	}
			 /*case 13:{//never use
				 fprintf(mid_code_file,"SAVE\n");
				 break;
			 }*/
	case 14: {
		if (strcmp(CODE_EMPTY, CODE_LIST.MID_CODE[number].result) == 0) {
			fprintf(mid_code_file, "CALL VALUE %s\n", CODE_LIST.MID_CODE[number].src1);
		}
		else {
			fprintf(mid_code_file, "CALL VALUE %s %s\n", CODE_LIST.MID_CODE[number].src1, CODE_LIST.MID_CODE[number].result);
		}
		break;
	}
	case 15: {
		fprintf(mid_code_file, "CALL VOID %s\n", CODE_LIST.MID_CODE[number].src1);
		break;
	}
	case 16: {
		fprintf(mid_code_file, "%s = %s <= %s\n", CODE_LIST.MID_CODE[number].result, CODE_LIST.MID_CODE[number].src1, CODE_LIST.MID_CODE[number].src2);
		break;
	}
	case 17: {
		fprintf(mid_code_file, "%s = %s < %s\n", CODE_LIST.MID_CODE[number].result, CODE_LIST.MID_CODE[number].src1, CODE_LIST.MID_CODE[number].src2);
		break;
	}
	case 18: {
		fprintf(mid_code_file, "%s = %s >= %s\n", CODE_LIST.MID_CODE[number].result, CODE_LIST.MID_CODE[number].src1, CODE_LIST.MID_CODE[number].src2);
		break;
	}
	case 19: {
		fprintf(mid_code_file, "%s = %s > %s\n", CODE_LIST.MID_CODE[number].result, CODE_LIST.MID_CODE[number].src1, CODE_LIST.MID_CODE[number].src2);
		break;
	}
	case 20: {
		fprintf(mid_code_file, "%s = %s == %s\n", CODE_LIST.MID_CODE[number].result, CODE_LIST.MID_CODE[number].src1, CODE_LIST.MID_CODE[number].src2);
		break;
	}
	case 21: {
		fprintf(mid_code_file, "%s = %s != %s\n", CODE_LIST.MID_CODE[number].result, CODE_LIST.MID_CODE[number].src1, CODE_LIST.MID_CODE[number].src2);
		break;
	}
	case 22: {
		fprintf(mid_code_file, "EQUZ %s %s\n", CODE_LIST.MID_CODE[number].src1, CODE_LIST.MID_CODE[number].src2);
		break;
	}
	case 23: {
		fprintf(mid_code_file, "NEQZ %s %s\n", CODE_LIST.MID_CODE[number].src1, CODE_LIST.MID_CODE[number].src2);
		break;
	}
	case 24: {
		fprintf(mid_code_file, "SET %s\n", CODE_LIST.MID_CODE[number].src1);
		break;
	}
	case 25: {
		fprintf(mid_code_file, "RT\n");
		break;
	}
	case 26: {
		fprintf(mid_code_file, "RT %s\n", CODE_LIST.MID_CODE[number].src1);
		break;
	}
	case 27: {
		fprintf(mid_code_file, "SCAN %s %s\n", CODE_LIST.MID_CODE[number].src1, CODE_LIST.MID_CODE[number].result);
		break;
	}
	case 28: {
		if (strcmp(CODE_EMPTY, CODE_LIST.MID_CODE[number].src1) == 0) {
			fprintf(mid_code_file, "PRINT %s %s\n", CODE_LIST.MID_CODE[number].result, CODE_LIST.MID_CODE[number].src2);
		}
		else if (strcmp(CODE_EMPTY, CODE_LIST.MID_CODE[number].src2) == 0) {
			fprintf(mid_code_file, "PRINT %s\n", CODE_LIST.MID_CODE[number].src1);
		}
		else {
			fprintf(mid_code_file, "PRINT %s %s %s\n", CODE_LIST.MID_CODE[number].src1, CODE_LIST.MID_CODE[number].result, CODE_LIST.MID_CODE[number].src2);
		}
		break;
	}
	case 29: {
		fprintf(mid_code_file, "%s = %s + %s\n", CODE_LIST.MID_CODE[number].result, CODE_LIST.MID_CODE[number].src1, CODE_LIST.MID_CODE[number].src2);
		break;
	}
	case 30: {
		fprintf(mid_code_file, "%s = %s - %s\n", CODE_LIST.MID_CODE[number].result, CODE_LIST.MID_CODE[number].src1, CODE_LIST.MID_CODE[number].src2);
		break;
	}
	case 31: {
		fprintf(mid_code_file, "%s = %s * %s\n", CODE_LIST.MID_CODE[number].result, CODE_LIST.MID_CODE[number].src1, CODE_LIST.MID_CODE[number].src2);
		break;
	}
	case 32: {
		fprintf(mid_code_file, "%s = %s / %s\n", CODE_LIST.MID_CODE[number].result, CODE_LIST.MID_CODE[number].src1, CODE_LIST.MID_CODE[number].src2);
		break;
	}
	case 33: {
		fprintf(mid_code_file, "GOTO %s\n", CODE_LIST.MID_CODE[number].src1);
		break;
	}
	case 34: {
		fprintf(mid_code_file, "END\n");
		break;
	}
	case 35: {
		fprintf(mid_code_file, "PUSH %s\n", CODE_LIST.MID_CODE[number].src1);
		break;
	}
	case 36: {
		fprintf(mid_code_file, "GET %s[%s] %s\n", CODE_LIST.MID_CODE[number].src1, CODE_LIST.MID_CODE[number].src2, CODE_LIST.MID_CODE[number].result);
		break;
	}
	case 37: {
		fprintf(mid_code_file, "NOP\n");
		break;
	}
	}
}


void init_func_list() {
	FUNC_BLOCKS.func_index = -1;
}

void add_func_block() {
	if (FUNC_BLOCKS.func_index == MAX_FUNC_BLOCK - 1) {
		error(OUT_OF_FUNC_BLOCK_ERROR, line);
		return;
	}
	FUNC_BLOCKS.func_index++;
	FUNC_BLOCKS.FUNC_LIST[FUNC_BLOCKS.func_index].start_num = CODE_LIST.code_num - 1;
	FUNC_BLOCKS.FUNC_LIST[FUNC_BLOCKS.func_index].b_block_index = -1;
	//printf("func: %d\n",FUNC_BLOCKS.FUNC_LIST[FUNC_BLOCKS.func_index].start_num);
}



//final_result.c  ����ʵ�֣�
//����ʵ��
void get_new_Table() {
	int index, f_index, i;
	new_Table.num_of_func = 0;
	new_Table.list_index = -1;
	for (index = 0; index < Table.index_of_func[0]; index++) {
		new_Table.list_index++;
		new_Table.List[new_Table.list_index].in_address = Table.List[index].in_address;
		new_Table.List[new_Table.list_index].kind = Table.List[index].kind;
		new_Table.List[new_Table.list_index].size = Table.List[index].size;
		new_Table.List[new_Table.list_index].type = Table.List[index].type;
		new_Table.List[new_Table.list_index].value = Table.List[index].value;
		strcpy(new_Table.List[new_Table.list_index].name, Table.List[index].name);
	}
	for (f_index = 0; f_index < Table.num_of_func; f_index++) {
		new_Table.index_of_func[new_Table.num_of_func] = new_Table.list_index + 1;
		if (f_index != Table.num_of_func - 1) {
			for (index = Table.index_of_func[f_index]; index < Table.index_of_func[f_index + 1]; index++) {
				if (Table.List[index].name[0] != '$') {
					new_Table.list_index++;
					new_Table.List[new_Table.list_index].in_address = Table.List[index].in_address;
					new_Table.List[new_Table.list_index].kind = Table.List[index].kind;
					new_Table.List[new_Table.list_index].size = Table.List[index].size;
					new_Table.List[new_Table.list_index].type = Table.List[index].type;
					new_Table.List[new_Table.list_index].value = Table.List[index].value;
					strcpy(new_Table.List[new_Table.list_index].name, Table.List[index].name);
				}
			}
			//����������޸ĺ�������ʱ����
			for (index = FUNC_BLOCKS.FUNC_LIST[f_index].start_num; index < FUNC_BLOCKS.FUNC_LIST[f_index + 1].start_num; index++) {
				if (CODE_LIST.MID_CODE[index].is_effective == 0)
					continue;
				if (strcmp(CODE_LIST.MID_CODE[index].result, CODE_EMPTY) == 0)
					continue;
				if (CODE_LIST.MID_CODE[index].result[0] == '$') {
					for (i = new_Table.index_of_func[new_Table.num_of_func]; i <= new_Table.list_index; i++) {
						if (strcmp(CODE_LIST.MID_CODE[index].result, new_Table.List[i].name) == 0)
							break;
					}
					if (i > new_Table.list_index) {
						new_Table.list_index++;
						new_Table.List[new_Table.list_index].in_address = new_Table.List[new_Table.list_index - 1].in_address + 1;
						new_Table.List[new_Table.list_index].kind = 1;
						new_Table.List[new_Table.list_index].size = -1;
						new_Table.List[new_Table.list_index].type = 1;
						new_Table.List[new_Table.list_index].value = 0;
						strcpy(new_Table.List[new_Table.list_index].name, CODE_LIST.MID_CODE[index].result);
					}
				}
			}
		}
		else {
			for (index = Table.index_of_func[f_index]; index <= Table.list_index; index++) {
				if (Table.List[index].name[0] != '$') {
					new_Table.list_index++;
					new_Table.List[new_Table.list_index].in_address = Table.List[index].in_address;
					new_Table.List[new_Table.list_index].kind = Table.List[index].kind;
					new_Table.List[new_Table.list_index].size = Table.List[index].size;
					new_Table.List[new_Table.list_index].type = Table.List[index].type;
					new_Table.List[new_Table.list_index].value = Table.List[index].value;
					strcpy(new_Table.List[new_Table.list_index].name, Table.List[index].name);
				}
			}
			//����������޸ĺ�������ʱ����
			for (index = FUNC_BLOCKS.FUNC_LIST[f_index].start_num; index < CODE_LIST.code_num; index++) {
				if (CODE_LIST.MID_CODE[index].is_effective == 0)
					continue;
				if (strcmp(CODE_LIST.MID_CODE[index].result, CODE_EMPTY) == 0)
					continue;
				if (CODE_LIST.MID_CODE[index].result[0] == '$') {
					for (i = new_Table.index_of_func[new_Table.num_of_func]; i <= new_Table.list_index; i++) {
						if (strcmp(CODE_LIST.MID_CODE[index].result, new_Table.List[i].name) == 0)
							break;
					}
					if (i > new_Table.list_index) {
						new_Table.list_index++;
						new_Table.List[new_Table.list_index].in_address = new_Table.List[new_Table.list_index - 1].in_address + 1;
						new_Table.List[new_Table.list_index].kind = 1;
						new_Table.List[new_Table.list_index].size = -1;
						new_Table.List[new_Table.list_index].type = 1;
						new_Table.List[new_Table.list_index].value = 0;
						strcpy(new_Table.List[new_Table.list_index].name, CODE_LIST.MID_CODE[index].result);
					}
				}
			}
		}
		new_Table.num_of_func++;
	}
}

void load_data(const char reg_name[], char var_name[]) {
	int address;
	if (islower(var_name[0]) || var_name[0] == '_' || var_name[0] == '$') {//Ҫȡ���Ǳ������߳���
		address = new_index_in_tab(var_name);
		if (new_global_flag) {
			if (new_const_flag) {
				fprintf(final_code, "li %s %d\n", reg_name, address);
			}
			else if (new_var_flag) {
				fprintf(final_code, "la $s7 %s\n", var_name);
				fprintf(final_code, "lw %s 0($s7)\n", reg_name);
			}
		}
		else {
			if (new_const_flag) {
				fprintf(final_code, "li %s %d\n", reg_name, address);
			}
			else if (new_var_flag) {
				fprintf(final_code, "lw %s %d($fp)\n", reg_name, -(address + 1) * 4);
			}
			else if (new_para_flag) {
				fprintf(final_code, "lw %s %d($fp)\n", reg_name, -(address + 1) * 4);
			}
		}
	}
	else { //�����������
		fprintf(final_code, "li %s %s\n", reg_name, var_name);
	}
}

void store_data(const char reg_name[], char var_name[]) {
	address = new_index_in_tab(var_name);
	if (new_global_flag) { //ȫ�ֱ�����Ӧ��ֱ�Ӵ��.data��Ӧ��������
		fprintf(final_code, "la $s7 %s\n", var_name);
		fprintf(final_code, "sw %s 0($s7)\n", reg_name);
	}
	else {
		fprintf(final_code, "sw %s %d($fp)\n", reg_name, -(address + 1) * 4);
	}
}
//���ݷ��ű��ȫ����������MIDCODE���ַ������м����д��.data
void data_area_generate() {
	int index, first_func_index;
	first_func_index = new_Table.index_of_func[0];
	for (index = 0; index < first_func_index; index++) {
		switch (new_Table.List[index].kind) {
		case 0: { //const
			fprintf(final_code, "%s: .word %d\n", new_Table.List[index].name, new_Table.List[index].value);
			break;
		}
		case 1: { //var
			if (new_Table.List[index].size != -1) {
				fprintf(final_code, "%s: .space %d\n", new_Table.List[index].name, new_Table.List[index].size * 4);
			}
			else {
				fprintf(final_code, "%s: .word 0\n", new_Table.List[index].name);
			}
		}
		}
	}
	for (index = 0; index < CODE_LIST.code_num; index++) {
		if ((CODE_LIST.MID_CODE[index].op == 28) && (strcmp(CODE_LIST.MID_CODE[index].src1, CODE_EMPTY) != 0))
			fprintf(final_code, "S%d: .asciiz %s\n", index, CODE_LIST.MID_CODE[index].src1);
	}
}
//����.text��
void generate_text() {
	int index, i;
	int address, size, para_num;
	char label1[50];
	char label2[50];
	for (index = 0; index < CODE_LIST.code_num; index++) {
		if (CODE_LIST.MID_CODE[index].is_effective == 0)
			continue;
		switch (CODE_LIST.MID_CODE[index].op) {
		case 7:
		case 8:
		case 9:
		{
			//init_reg_var_list();
			strcpy(now_func_name, CODE_LIST.MID_CODE[index].src1);
			//�γ��µ�����ջ
			size = get_func_total_size(CODE_LIST.MID_CODE[index].src1);
			size = size + 2;
			//sizeһ����Ӧ�ĵط������оֲ���������+���ص�ַ��������һ��AR��fp��ַ
			fprintf(final_code, "%s:\n", CODE_LIST.MID_CODE[index].src1);
			para_num = get_func_para_num(now_func_name);
			for (i = 0; i < para_num; i++) {
				fprintf(final_code, "lw $s7 0($sp)\n");
				fprintf(final_code, "subi $sp $sp 8\n");
				fprintf(final_code, "sw $s7 0($sp)\n");
				fprintf(final_code, "addi $sp $sp 12\n");
			}
			fprintf(final_code, "move $s7 $fp\n");
			fprintf(final_code, "move $fp $sp\n");
			fprintf(final_code, "subi $fp $fp 4\n");
			fprintf(final_code, "sw $s7 0($fp)\n");
			fprintf(final_code, "sw $ra -4($fp)\n");
			fprintf(final_code, "subi $sp $sp %d\n", size * 4);
			break;
		}
		case 11: {
			load_data("$t0", CODE_LIST.MID_CODE[index].src1);
			store_data("$t0", CODE_LIST.MID_CODE[index].result);
			break;
		}
		case 12: {
			load_data("$t0", CODE_LIST.MID_CODE[index].src1);
			load_data("$t1", CODE_LIST.MID_CODE[index].src2);
			fprintf(final_code, "li $s6 4\n");
			fprintf(final_code, "mul $s6 $s6 $t1\n");
			address = new_index_in_tab(CODE_LIST.MID_CODE[index].result);
			if (new_global_flag) {
				fprintf(final_code, "la $s7 %s\n", CODE_LIST.MID_CODE[index].result);
				fprintf(final_code, "add $s7 $s7 $s6\n");
				fprintf(final_code, "sw $t0 0($s7)\n");
			}
			else {
				fprintf(final_code, "subi $s7 $fp %d\n", (address + 1) * 4);
				fprintf(final_code, "add $s7 $s7 $s6\n");
				fprintf(final_code, "sw $t0 0($s7)\n");
			}
			break;
		}
				 /*case 13:{
					 save_scene();
					 break;
				 }*/
		case 14: {//��ΪҪ��ֵ�Ͳ�Ҫ
			/*1.�����ֳ�
			  2.jal
			  3.������Ҫ��v0���Ƹ�result
			*/
			fprintf(final_code, "jal %s\n", CODE_LIST.MID_CODE[index].src1);
			if (strcmp(CODE_EMPTY, CODE_LIST.MID_CODE[index].result) != 0) {
				fprintf(final_code, "move $t0 $v0\n");
				store_data("$t0", CODE_LIST.MID_CODE[index].result);
			}
			break;
		}
		case 15: {
			fprintf(final_code, "jal %s\n", CODE_LIST.MID_CODE[index].src1);
			break;
		}
		case 16: {
			generate_label(label1);
			generate_label(label2);
			load_data("$t0", CODE_LIST.MID_CODE[index].src1);
			load_data("$t1", CODE_LIST.MID_CODE[index].src2);
			fprintf(final_code, "ble $t0 $t1 %s\n", label1);
			store_data("$zero", CODE_LIST.MID_CODE[index].result);
			fprintf(final_code, "j %s\n", label2);
			fprintf(final_code, "%s:\n", label1);
			fprintf(final_code, "li $t2 1\n");
			store_data("$t2", CODE_LIST.MID_CODE[index].result);
			fprintf(final_code, "%s:\n", label2);
			break;
		}
		case 17: {
			generate_label(label1);
			generate_label(label2);
			load_data("$t0", CODE_LIST.MID_CODE[index].src1);
			load_data("$t1", CODE_LIST.MID_CODE[index].src2);
			fprintf(final_code, "blt $t0 $t1 %s\n", label1);
			store_data("$zero", CODE_LIST.MID_CODE[index].result);
			fprintf(final_code, "j %s\n", label2);
			fprintf(final_code, "%s:\n", label1);
			fprintf(final_code, "li $t2 1\n");
			store_data("$t2", CODE_LIST.MID_CODE[index].result);
			fprintf(final_code, "%s:\n", label2);
			break;
		}
		case 18: {
			generate_label(label1);
			generate_label(label2);
			load_data("$t0", CODE_LIST.MID_CODE[index].src1);
			load_data("$t1", CODE_LIST.MID_CODE[index].src2);
			fprintf(final_code, "bge $t0 $t1 %s\n", label1);
			store_data("$zero", CODE_LIST.MID_CODE[index].result);
			fprintf(final_code, "j %s\n", label2);
			fprintf(final_code, "%s:\n", label1);
			fprintf(final_code, "li $t2 1\n");
			store_data("$t2", CODE_LIST.MID_CODE[index].result);
			fprintf(final_code, "%s:\n", label2);
			break;
		}
		case 19: {
			generate_label(label1);
			generate_label(label2);
			load_data("$t0", CODE_LIST.MID_CODE[index].src1);
			load_data("$t1", CODE_LIST.MID_CODE[index].src2);
			fprintf(final_code, "bgt $t0 $t1 %s\n", label1);
			store_data("$zero", CODE_LIST.MID_CODE[index].result);
			fprintf(final_code, "j %s\n", label2);
			fprintf(final_code, "%s:\n", label1);
			fprintf(final_code, "li $t2 1\n");
			store_data("$t2", CODE_LIST.MID_CODE[index].result);
			fprintf(final_code, "%s:\n", label2);
			break;
		}
		case 20: {
			generate_label(label1);
			generate_label(label2);
			load_data("$t0", CODE_LIST.MID_CODE[index].src1);
			load_data("$t1", CODE_LIST.MID_CODE[index].src2);
			fprintf(final_code, "beq $t0 $t1 %s\n", label1);
			store_data("$zero", CODE_LIST.MID_CODE[index].result);
			fprintf(final_code, "j %s\n", label2);
			fprintf(final_code, "%s:\n", label1);
			fprintf(final_code, "li $t2 1\n");
			store_data("$t2", CODE_LIST.MID_CODE[index].result);
			fprintf(final_code, "%s:\n", label2);
			break;
		}
		case 21: {
			generate_label(label1);
			generate_label(label2);
			load_data("$t0", CODE_LIST.MID_CODE[index].src1);
			load_data("$t1", CODE_LIST.MID_CODE[index].src2);
			fprintf(final_code, "bne $t0 $t1 %s\n", label1);
			store_data("$zero", CODE_LIST.MID_CODE[index].result);
			fprintf(final_code, "j %s\n", label2);
			fprintf(final_code, "%s:\n", label1);
			fprintf(final_code, "li $t2 1\n");
			store_data("$t2", CODE_LIST.MID_CODE[index].result);
			fprintf(final_code, "%s:\n", label2);
			break;
		}
		case 22: {
			load_data("$t0", CODE_LIST.MID_CODE[index].src1);
			fprintf(final_code, "beq $t0 $zero %s\n", CODE_LIST.MID_CODE[index].src2);
			break;
		}
		case 23: {
			load_data("$t0", CODE_LIST.MID_CODE[index].src1);
			fprintf(final_code, "bne $t0 $zero %s\n", CODE_LIST.MID_CODE[index].src2);
			break;
		}
		case 24: {
			fprintf(final_code, "%s:\n", CODE_LIST.MID_CODE[index].src1);
			break;
		}
				 //?
		case 25: {
			fprintf(final_code, "lw $ra -4($fp)\n");
			fprintf(final_code, "addi $sp $fp 4\n");
			fprintf(final_code, "lw $fp 0($fp)\n");
			fprintf(final_code, "jr $ra\n");
			break;
		}
		case 26: {
			load_data("$t0", CODE_LIST.MID_CODE[index].src1);
			fprintf(final_code, "move $v0 $t0\n");
			fprintf(final_code, "lw $ra -4($fp)\n");
			fprintf(final_code, "addi $sp $fp 4\n");
			fprintf(final_code, "lw $fp 0($fp)\n");
			fprintf(final_code, "jr $ra\n");
			break;
		}
		case 27: {
			if (strcmp(CODE_INT, CODE_LIST.MID_CODE[index].src1) == 0) {
				fprintf(final_code, "li $v0 5\n");
				fprintf(final_code, "syscall\n");
				fprintf(final_code, "move $t0 $v0\n");
				store_data("$t0", CODE_LIST.MID_CODE[index].result);
			}
			else {
				fprintf(final_code, "li $v0 12\n");
				fprintf(final_code, "syscall\n");
				fprintf(final_code, "move $t0 $v0\n");
				store_data("$t0", CODE_LIST.MID_CODE[index].result);
			}
			break;
		}
		case 28: {
			if (strcmp(CODE_LIST.MID_CODE[index].src1, CODE_EMPTY) != 0) {
				fprintf(final_code, "la $a0 S%d\n", index);
				fprintf(final_code, "li $v0 4\n");
				fprintf(final_code, "syscall\n");
			}
			if (strcmp(CODE_LIST.MID_CODE[index].src2, CODE_EMPTY) != 0) {
				load_data("$t0", CODE_LIST.MID_CODE[index].src2);
				if (strcmp(CODE_LIST.MID_CODE[index].result, CODE_CHAR) == 0) {
					fprintf(final_code, "move $a0 $t0\n");
					fprintf(final_code, "li $v0 11\n");
					fprintf(final_code, "syscall\n");
				}
				else {
					fprintf(final_code, "move $a0 $t0\n");
					fprintf(final_code, "li $v0 1\n");
					fprintf(final_code, "syscall\n");
				}
			}
			break;
		}
		case 29: {
			load_data("$t0", CODE_LIST.MID_CODE[index].src1);
			load_data("$t1", CODE_LIST.MID_CODE[index].src2);
			fprintf(final_code, "add $t0 $t0 $t1\n");
			store_data("$t0", CODE_LIST.MID_CODE[index].result);
			break;
		}
		case 30: {
			load_data("$t0", CODE_LIST.MID_CODE[index].src1);
			load_data("$t1", CODE_LIST.MID_CODE[index].src2);
			fprintf(final_code, "sub $t0 $t0 $t1\n");
			store_data("$t0", CODE_LIST.MID_CODE[index].result);
			break;
		}
		case 31: {
			load_data("$t0", CODE_LIST.MID_CODE[index].src1);
			load_data("$t1", CODE_LIST.MID_CODE[index].src2);
			fprintf(final_code, "mul $t0 $t0 $t1\n");
			store_data("$t0", CODE_LIST.MID_CODE[index].result);
			break;
		}
		case 32: {
			load_data("$t0", CODE_LIST.MID_CODE[index].src1);
			load_data("$t1", CODE_LIST.MID_CODE[index].src2);
			fprintf(final_code, "div $t0 $t1\n");
			fprintf(final_code, "mflo $t0\n");
			store_data("$t0", CODE_LIST.MID_CODE[index].result);
			break;
		}
		case 33: {
			fprintf(final_code, "j %s\n", CODE_LIST.MID_CODE[index].src1);
			break;
		}
		case 34: {
			fprintf(final_code, "li $v0 10\n");
			fprintf(final_code, "syscall\n");
			break;
		}
		case 35: {
			load_data("$t0", CODE_LIST.MID_CODE[index].src1);
			fprintf(final_code, "subi $sp $sp 4\n");
			fprintf(final_code, "sw $t0 0($sp)\n");
			break;
		}
		case 36: {
			load_data("$t0", CODE_LIST.MID_CODE[index].src2);
			fprintf(final_code, "li $s6 4\n");
			fprintf(final_code, "mul $s6 $s6 $t0\n");
			address = new_index_in_tab(CODE_LIST.MID_CODE[index].src1);
			if (new_global_flag) {
				fprintf(final_code, "la $s7 %s\n", CODE_LIST.MID_CODE[index].src1);
				fprintf(final_code, "add $s7 $s7 $s6\n");
				fprintf(final_code, "lw $t1 0($s7)\n");
				store_data("$t1", CODE_LIST.MID_CODE[index].result);
			}
			else {
				fprintf(final_code, "subi $s7 $fp %d\n", (1 + address) * 4);
				fprintf(final_code, "add $s7 $s7 $s6\n");
				fprintf(final_code, "lw $t1 0($s7)\n");
				store_data("$t1", CODE_LIST.MID_CODE[index].result);
			}
			break;
		}
		}
	}
}

int new_index_in_tab(char name[]) {
	int index, i;
	new_const_flag = 0;
	new_var_flag = 0;
	new_para_flag = 0;
	new_global_flag = 0;
	if (strcmp(now_func_name, CODE_EMPTY) == 0) { //ȫ��������ȫ��������
		for (index = 0; new_Table.List[index].kind != 2; index++) {
			if (strcmp(new_Table.List[index].name, name) == 0)
				break;
		}
		if (new_Table.List[index].kind == 2)
			return -1;
		else {
			new_global_flag = 1;
			if (new_Table.List[index].kind == 0) {
				new_const_flag = 1;
				return new_Table.List[index].value;
			}
			else if (new_Table.List[index].kind == 1) {
				new_var_flag = 1;
				return new_Table.List[index].in_address;
			}
			return -1;
		}
	}
	else {
		for (index = 0; index < new_Table.num_of_func; index++) {
			i = new_Table.index_of_func[index];
			if (strcmp(new_Table.List[i].name, now_func_name) == 0)
				break;
		}
		if (index < new_Table.num_of_func) {
			for (index = i + 1; (index <= new_Table.list_index) && (new_Table.List[index].kind != 2); index++)
				if (strcmp(new_Table.List[index].name, name) == 0)
					break;
			if ((index <= new_Table.list_index) && (new_Table.List[index].kind != 2)) {
				if (new_Table.List[index].kind == 0) {
					new_const_flag = 1;
					return new_Table.List[index].value;
				}
				else if (new_Table.List[index].kind == 1) {
					new_var_flag = 1;
					return new_Table.List[index].in_address;
				}
				else if (new_Table.List[index].kind == 3) {
					new_para_flag = 1;
					return new_Table.List[index].in_address;
				}
				return -1;
			}
			else {//ȥȫ������
				for (index = 0; new_Table.List[index].kind != 2; index++) {
					if (strcmp(new_Table.List[index].name, name) == 0)
						break;
				}
				if (new_Table.List[index].kind == 2)
					return -1;
				else {
					new_global_flag = 1;
					if (new_Table.List[index].kind == 0) {
						new_const_flag = 1;
						return new_Table.List[index].value;
					}
					else if (new_Table.List[index].kind == 1) {
						new_var_flag = 1;
						return new_Table.List[index].in_address;
					}
					return -1;
				}
			}
		}
		else {//error
			return -1;
		}
	}
	return -1;
}

int get_func_para_num(char name[]) {
	int index;
	for (index = 0; index < new_Table.num_of_func; index++) {
		if (strcmp(name, new_Table.List[new_Table.index_of_func[index]].name) == 0)
			break;
	}
	if (index < new_Table.num_of_func) {
		return(new_Table.List[new_Table.index_of_func[index]].size);
	}
	else {
		return -1;
	}
}

int get_func_total_size(char name[]) {
	int i, index;
	for (i = 0; i < new_Table.num_of_func; i++) {
		index = new_Table.index_of_func[i];
		if (strcmp(name, new_Table.List[index].name) == 0)
			break;
	}
	if (i == new_Table.num_of_func) {
		error(FUNC_NO_DEF_ERROR, line);
		return -1;
	}
	else {       //�ҵ���ͬ������
		if (i < new_Table.num_of_func - 1) {
			return(new_Table.List[new_Table.index_of_func[i + 1] - 1].in_address);
		}
		else {
			return(new_Table.List[new_Table.list_index].in_address);
		}
	}
}

//�������մ�����ܴ���
void generate_all_final_code() {
	get_new_Table();
	strcmp(now_func_name, CODE_EMPTY);
	final_code = fopen("final.asm", "w");
	fprintf(final_code, ".data\n");
	data_area_generate();
	fprintf(final_code, ".text\n");
	fprintf(final_code, "move $fp $sp\n");
	fprintf(final_code, "j main\n");
	generate_text();
	fclose(final_code);
}




int main()
{
	char data_path[100];
	scanf("%s", data_path);
	if ((compile_file = fopen(data_path, "r")) == NULL) {
		printf("Can not find the file.\n");
		return 0;
	}

	output_file = fopen("result.txt", "w");
	initial_table();
	init_code_list();
	init_func_list();
	CHAR = get_ch();

	symbol = insymbol();   //����ֻ����һ��symbol�����Ƕ���֮��ָ���Ѿ�ָ����һ��λ��
	program();
	fprintf(output_file, "finish compiling\n");
	print_mid_code();
	generate_all_final_code();

	fclose(compile_file);
	fclose(output_file);
	return 0;

}