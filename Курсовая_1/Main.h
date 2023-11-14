#pragma once
#include <iostream>
#include <filesystem>
#include <Vector>
#include"Table.h"
#include <msclr\marshal_cppstd.h>
#include"Tree.h"
#include <set>
#include "Order.h"
#include "RBTree.h"
#include "List.h"
#include "LisMt.h"
#include "Clients_comparasion.h"
#include "Clients.h"
#include "AVL.h"
#include "HashTable.h"
#include <chrono>
#include "HashTableD.h"
#include "HashTableD.cpp"

namespace Курсовая1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	std::vector<list*> Record_cars = std::vector<list*>(0);
	std::vector<Person*> Record_clients = std::vector<Person*>(0);
	std::vector<Denis::Order*> Record_orders = std::vector<Denis::Order*>(0);

	tree* TreeBrand;
	tree* TreeModal;
	tree* TreeColor;

	BST<Adress>* TreeAdress = new BST<Adress>();
	BST<FIO>* TreeFIO = new BST<FIO>();
	BST<DB>* TreeDB = new BST<DB>();

	Denis::RBTree<Denis::Date>* TreeDate = new Denis::RBTree<Denis::Date>();
	Denis::RBTree<int>* TreeNum = new Denis::RBTree<int>();
	Denis::RBTree<std::string>* TreeCarNum = new Denis::RBTree<std::string>();
	Denis::RBTree<int>* TreeLength = new Denis::RBTree<int>();

	int HashTable_size = 15;
	HT* Hashtable = new HT(HashTable_size);
	HashTable* MHashtable = new HashTable(HashTable_size);
	Denis::HashTable* DHashtable = new Denis::HashTable();
	

	bool import = false;
	bool importM = false;
	bool importD = false;

	std::string CarNum = "ABEKMHOPCTYX";

	/// <summary>
	/// Сводка для Main
	/// </summary>
	public ref class Main : public System::Windows::Forms::Form
	{
	public:
		Main(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~Main()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ button_exit;
	private: System::Windows::Forms::TabPage^ tabPage_orders;
	private: System::Windows::Forms::TabPage^ tabPage_clients;
	private: System::Windows::Forms::TabPage^ tabPage_cars;
	private: System::Windows::Forms::TabControl^ tabControl;
	private: System::Windows::Forms::RichTextBox^ richTextBox_cars_structure;

	private: System::Windows::Forms::RichTextBox^ richTextBox_cars_data;

	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ textBox_car_color;

	private: System::Windows::Forms::TextBox^ textBox_car_brand;
	private: System::Windows::Forms::TextBox^ textBox_car_model;


	private: System::Windows::Forms::TextBox^ textBox_car_num;
	private: System::Windows::Forms::TextBox^ textBox_car_2letter;


	private: System::Windows::Forms::TextBox^ textBox_car_1letter;

	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Button^ button_delete_cars;
	private: System::Windows::Forms::Button^ button_find_cars;


	private: System::Windows::Forms::Button^ button_add_cars;

	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Button^ button_cars_tree_brand;
	private: System::Windows::Forms::Button^ button_cars_hashtable;



	private: System::Windows::Forms::Button^ button_cars_tree_model;
	private: System::Windows::Forms::TextBox^ textBox_car_size_HT;
	private: System::Windows::Forms::Button^ button_orders_date;





	private: System::Windows::Forms::Button^ button_orders_number;

	private: System::Windows::Forms::Button^ button_orders_HT;
	private: System::Windows::Forms::Button^ button_orders_pnumber;


	private: System::Windows::Forms::Button^ button_orders_delete;
	private: System::Windows::Forms::Button^ button_orders_find;




	private: System::Windows::Forms::Button^ button_orders_add;



	private: System::Windows::Forms::Label^ label14;
	private: System::Windows::Forms::Label^ label15;
	private: System::Windows::Forms::TextBox^ textBox_orders_num;
	private: System::Windows::Forms::TextBox^ textBox_orders_2letter;





	private: System::Windows::Forms::TextBox^ textBox_orders_1letterr;
	private: System::Windows::Forms::RichTextBox^ richTextBox_orders_data;
	private: System::Windows::Forms::RichTextBox^ richTextBox_orders_structure;



	private: System::Windows::Forms::TextBox^ textBox_clients_size_HT;





	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Button^ button12;
	private: System::Windows::Forms::Button^ button13;
	private: System::Windows::Forms::Button^ button14;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::Label^ label10;
	private: System::Windows::Forms::TextBox^ textBox_clients_address;
	private: System::Windows::Forms::TextBox^ textBox_clients_surname;
private: System::Windows::Forms::RichTextBox^ richTextBox_clients_data;
private: System::Windows::Forms::RichTextBox^ richTextBox_clients_structure;









	private: System::Windows::Forms::Button^ button_cars_trees_color;

	private: System::Windows::Forms::Label^ label16;
private: System::Windows::Forms::TextBox^ textBox_clients_num;

private: System::Windows::Forms::TextBox^ textBox_clients_name;
private: System::Windows::Forms::TextBox^ textBox_clients_lastname;




	private: System::Windows::Forms::Label^ label18;
	private: System::Windows::Forms::Label^ label17;
private: System::Windows::Forms::TextBox^ textBox_orders_pnum;

	private: System::Windows::Forms::Label^ label12;
	private: System::Windows::Forms::Label^ label19;

	private: System::Windows::Forms::Label^ label13;
private: System::Windows::Forms::ComboBox^ comboBox_orders_length;


private: System::Windows::Forms::Button^ button8;
private: System::Windows::Forms::Button^ button9;
private: System::Windows::Forms::Button^ button10;
private: System::Windows::Forms::Button^ button11;
private: System::Windows::Forms::Button^ button_export;

private: System::Windows::Forms::Button^ button_import;
private: System::Windows::Forms::Button^ button_orders_length;

private: System::Windows::Forms::RadioButton^ radioButton_cars_color;

private: System::Windows::Forms::RadioButton^ radioButton_cars_model;

private: System::Windows::Forms::RadioButton^ radioButton_cars_brand;

private: System::Windows::Forms::RadioButton^ radioButton_cars_label;
private: System::Windows::Forms::RadioButton^ radioButton_clients_adress;
private: System::Windows::Forms::RadioButton^ radioButton_clients_num;
private: System::Windows::Forms::RadioButton^ radioButton_clients_DB;
private: System::Windows::Forms::RadioButton^ radioButton_clients_FIO;
private: System::Windows::Forms::Button^ button_clients_export;
private: System::Windows::Forms::Button^ button_clietns_import;
private: System::Windows::Forms::RadioButton^ radioButton_orders_comb;

private: System::Windows::Forms::RadioButton^ radioButton_orders_number;
private: System::Windows::Forms::RadioButton^ radioButton_orders_pnumber;
private: System::Windows::Forms::RadioButton^ radioButton_orders_date;
private: System::Windows::Forms::RadioButton^ radioButton_orders_length;




private: System::Windows::Forms::TextBox^ textBox_clients_db;
private: System::Windows::Forms::TextBox^ textBox_orders_year;

private: System::Windows::Forms::TextBox^ textBox_orders_month;

private: System::Windows::Forms::TextBox^ textBox_orders_day;
private: System::Windows::Forms::Button^ button_orders_export;
private: System::Windows::Forms::Button^ button_orders_import;





























	protected:

	protected:

	protected:

	protected:

	protected:

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Main::typeid));
			this->button_exit = (gcnew System::Windows::Forms::Button());
			this->tabPage_orders = (gcnew System::Windows::Forms::TabPage());
			this->button_orders_export = (gcnew System::Windows::Forms::Button());
			this->button_orders_import = (gcnew System::Windows::Forms::Button());
			this->textBox_orders_year = (gcnew System::Windows::Forms::TextBox());
			this->textBox_orders_month = (gcnew System::Windows::Forms::TextBox());
			this->textBox_orders_day = (gcnew System::Windows::Forms::TextBox());
			this->radioButton_orders_comb = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton_orders_number = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton_orders_pnumber = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton_orders_date = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton_orders_length = (gcnew System::Windows::Forms::RadioButton());
			this->button_orders_length = (gcnew System::Windows::Forms::Button());
			this->comboBox_orders_length = (gcnew System::Windows::Forms::ComboBox());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->textBox_orders_pnum = (gcnew System::Windows::Forms::TextBox());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->label19 = (gcnew System::Windows::Forms::Label());
			this->button_orders_date = (gcnew System::Windows::Forms::Button());
			this->button_orders_number = (gcnew System::Windows::Forms::Button());
			this->button_orders_HT = (gcnew System::Windows::Forms::Button());
			this->button_orders_pnumber = (gcnew System::Windows::Forms::Button());
			this->button_orders_delete = (gcnew System::Windows::Forms::Button());
			this->button_orders_find = (gcnew System::Windows::Forms::Button());
			this->button_orders_add = (gcnew System::Windows::Forms::Button());
			this->label14 = (gcnew System::Windows::Forms::Label());
			this->label15 = (gcnew System::Windows::Forms::Label());
			this->textBox_orders_num = (gcnew System::Windows::Forms::TextBox());
			this->textBox_orders_2letter = (gcnew System::Windows::Forms::TextBox());
			this->textBox_orders_1letterr = (gcnew System::Windows::Forms::TextBox());
			this->richTextBox_orders_data = (gcnew System::Windows::Forms::RichTextBox());
			this->richTextBox_orders_structure = (gcnew System::Windows::Forms::RichTextBox());
			this->tabPage_clients = (gcnew System::Windows::Forms::TabPage());
			this->textBox_clients_db = (gcnew System::Windows::Forms::TextBox());
			this->button_clients_export = (gcnew System::Windows::Forms::Button());
			this->button_clietns_import = (gcnew System::Windows::Forms::Button());
			this->radioButton_clients_adress = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton_clients_num = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton_clients_DB = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton_clients_FIO = (gcnew System::Windows::Forms::RadioButton());
			this->button8 = (gcnew System::Windows::Forms::Button());
			this->button9 = (gcnew System::Windows::Forms::Button());
			this->button10 = (gcnew System::Windows::Forms::Button());
			this->button11 = (gcnew System::Windows::Forms::Button());
			this->textBox_clients_name = (gcnew System::Windows::Forms::TextBox());
			this->textBox_clients_lastname = (gcnew System::Windows::Forms::TextBox());
			this->label18 = (gcnew System::Windows::Forms::Label());
			this->label17 = (gcnew System::Windows::Forms::Label());
			this->textBox_clients_num = (gcnew System::Windows::Forms::TextBox());
			this->label16 = (gcnew System::Windows::Forms::Label());
			this->textBox_clients_size_HT = (gcnew System::Windows::Forms::TextBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->button12 = (gcnew System::Windows::Forms::Button());
			this->button13 = (gcnew System::Windows::Forms::Button());
			this->button14 = (gcnew System::Windows::Forms::Button());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->textBox_clients_address = (gcnew System::Windows::Forms::TextBox());
			this->textBox_clients_surname = (gcnew System::Windows::Forms::TextBox());
			this->richTextBox_clients_data = (gcnew System::Windows::Forms::RichTextBox());
			this->richTextBox_clients_structure = (gcnew System::Windows::Forms::RichTextBox());
			this->tabPage_cars = (gcnew System::Windows::Forms::TabPage());
			this->radioButton_cars_color = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton_cars_model = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton_cars_brand = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton_cars_label = (gcnew System::Windows::Forms::RadioButton());
			this->button_export = (gcnew System::Windows::Forms::Button());
			this->button_import = (gcnew System::Windows::Forms::Button());
			this->button_cars_trees_color = (gcnew System::Windows::Forms::Button());
			this->button_cars_tree_brand = (gcnew System::Windows::Forms::Button());
			this->button_cars_hashtable = (gcnew System::Windows::Forms::Button());
			this->button_cars_tree_model = (gcnew System::Windows::Forms::Button());
			this->textBox_car_size_HT = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->button_delete_cars = (gcnew System::Windows::Forms::Button());
			this->button_find_cars = (gcnew System::Windows::Forms::Button());
			this->button_add_cars = (gcnew System::Windows::Forms::Button());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBox_car_color = (gcnew System::Windows::Forms::TextBox());
			this->textBox_car_brand = (gcnew System::Windows::Forms::TextBox());
			this->textBox_car_model = (gcnew System::Windows::Forms::TextBox());
			this->textBox_car_num = (gcnew System::Windows::Forms::TextBox());
			this->textBox_car_2letter = (gcnew System::Windows::Forms::TextBox());
			this->textBox_car_1letter = (gcnew System::Windows::Forms::TextBox());
			this->richTextBox_cars_data = (gcnew System::Windows::Forms::RichTextBox());
			this->richTextBox_cars_structure = (gcnew System::Windows::Forms::RichTextBox());
			this->tabControl = (gcnew System::Windows::Forms::TabControl());
			this->tabPage_orders->SuspendLayout();
			this->tabPage_clients->SuspendLayout();
			this->tabPage_cars->SuspendLayout();
			this->tabControl->SuspendLayout();
			this->SuspendLayout();
			// 
			// button_exit
			// 
			this->button_exit->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(207)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(6)));
			this->button_exit->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button_exit->Location = System::Drawing::Point(1178, 0);
			this->button_exit->Name = L"button_exit";
			this->button_exit->Size = System::Drawing::Size(36, 27);
			this->button_exit->TabIndex = 0;
			this->button_exit->UseVisualStyleBackColor = false;
			this->button_exit->Click += gcnew System::EventHandler(this, &Main::button1_Click);
			// 
			// tabPage_orders
			// 
			this->tabPage_orders->Controls->Add(this->button_orders_export);
			this->tabPage_orders->Controls->Add(this->button_orders_import);
			this->tabPage_orders->Controls->Add(this->textBox_orders_year);
			this->tabPage_orders->Controls->Add(this->textBox_orders_month);
			this->tabPage_orders->Controls->Add(this->textBox_orders_day);
			this->tabPage_orders->Controls->Add(this->radioButton_orders_comb);
			this->tabPage_orders->Controls->Add(this->radioButton_orders_number);
			this->tabPage_orders->Controls->Add(this->radioButton_orders_pnumber);
			this->tabPage_orders->Controls->Add(this->radioButton_orders_date);
			this->tabPage_orders->Controls->Add(this->radioButton_orders_length);
			this->tabPage_orders->Controls->Add(this->button_orders_length);
			this->tabPage_orders->Controls->Add(this->comboBox_orders_length);
			this->tabPage_orders->Controls->Add(this->label13);
			this->tabPage_orders->Controls->Add(this->textBox_orders_pnum);
			this->tabPage_orders->Controls->Add(this->label12);
			this->tabPage_orders->Controls->Add(this->label19);
			this->tabPage_orders->Controls->Add(this->button_orders_date);
			this->tabPage_orders->Controls->Add(this->button_orders_number);
			this->tabPage_orders->Controls->Add(this->button_orders_HT);
			this->tabPage_orders->Controls->Add(this->button_orders_pnumber);
			this->tabPage_orders->Controls->Add(this->button_orders_delete);
			this->tabPage_orders->Controls->Add(this->button_orders_find);
			this->tabPage_orders->Controls->Add(this->button_orders_add);
			this->tabPage_orders->Controls->Add(this->label14);
			this->tabPage_orders->Controls->Add(this->label15);
			this->tabPage_orders->Controls->Add(this->textBox_orders_num);
			this->tabPage_orders->Controls->Add(this->textBox_orders_2letter);
			this->tabPage_orders->Controls->Add(this->textBox_orders_1letterr);
			this->tabPage_orders->Controls->Add(this->richTextBox_orders_data);
			this->tabPage_orders->Controls->Add(this->richTextBox_orders_structure);
			this->tabPage_orders->Location = System::Drawing::Point(4, 29);
			this->tabPage_orders->Name = L"tabPage_orders";
			this->tabPage_orders->Padding = System::Windows::Forms::Padding(3);
			this->tabPage_orders->Size = System::Drawing::Size(1208, 622);
			this->tabPage_orders->TabIndex = 2;
			this->tabPage_orders->Text = L"Заказы";
			this->tabPage_orders->UseVisualStyleBackColor = true;
			this->tabPage_orders->Click += gcnew System::EventHandler(this, &Main::tabPage3_Click);
			// 
			// button_orders_export
			// 
			this->button_orders_export->Location = System::Drawing::Point(634, 519);
			this->button_orders_export->Name = L"button_orders_export";
			this->button_orders_export->Size = System::Drawing::Size(95, 43);
			this->button_orders_export->TabIndex = 68;
			this->button_orders_export->Text = L"Экспорт";
			this->button_orders_export->UseVisualStyleBackColor = true;
			this->button_orders_export->Click += gcnew System::EventHandler(this, &Main::button_orders_export_Click);
			// 
			// button_orders_import
			// 
			this->button_orders_import->Location = System::Drawing::Point(634, 451);
			this->button_orders_import->Name = L"button_orders_import";
			this->button_orders_import->Size = System::Drawing::Size(94, 44);
			this->button_orders_import->TabIndex = 67;
			this->button_orders_import->Text = L"Импорт";
			this->button_orders_import->UseVisualStyleBackColor = true;
			this->button_orders_import->Click += gcnew System::EventHandler(this, &Main::button_orders_import_Click);
			// 
			// textBox_orders_year
			// 
			this->textBox_orders_year->Location = System::Drawing::Point(133, 553);
			this->textBox_orders_year->Name = L"textBox_orders_year";
			this->textBox_orders_year->Size = System::Drawing::Size(84, 26);
			this->textBox_orders_year->TabIndex = 66;
			this->textBox_orders_year->TextChanged += gcnew System::EventHandler(this, &Main::textBox_orders_year_TextChanged);
			// 
			// textBox_orders_month
			// 
			this->textBox_orders_month->Location = System::Drawing::Point(72, 553);
			this->textBox_orders_month->Name = L"textBox_orders_month";
			this->textBox_orders_month->Size = System::Drawing::Size(55, 26);
			this->textBox_orders_month->TabIndex = 65;
			this->textBox_orders_month->TextChanged += gcnew System::EventHandler(this, &Main::textBox_orders_month_TextChanged);
			// 
			// textBox_orders_day
			// 
			this->textBox_orders_day->Location = System::Drawing::Point(11, 552);
			this->textBox_orders_day->Name = L"textBox_orders_day";
			this->textBox_orders_day->Size = System::Drawing::Size(55, 26);
			this->textBox_orders_day->TabIndex = 64;
			this->textBox_orders_day->TextChanged += gcnew System::EventHandler(this, &Main::textBox_orders_day_TextChanged);
			// 
			// radioButton_orders_comb
			// 
			this->radioButton_orders_comb->AutoSize = true;
			this->radioButton_orders_comb->Location = System::Drawing::Point(735, 545);
			this->radioButton_orders_comb->Name = L"radioButton_orders_comb";
			this->radioButton_orders_comb->Size = System::Drawing::Size(150, 24);
			this->radioButton_orders_comb->TabIndex = 63;
			this->radioButton_orders_comb->TabStop = true;
			this->radioButton_orders_comb->Text = L"По комбинации";
			this->radioButton_orders_comb->UseVisualStyleBackColor = true;
			// 
			// radioButton_orders_number
			// 
			this->radioButton_orders_number->AutoSize = true;
			this->radioButton_orders_number->Location = System::Drawing::Point(735, 427);
			this->radioButton_orders_number->Name = L"radioButton_orders_number";
			this->radioButton_orders_number->Size = System::Drawing::Size(137, 24);
			this->radioButton_orders_number->TabIndex = 62;
			this->radioButton_orders_number->TabStop = true;
			this->radioButton_orders_number->Text = L"По госномеру";
			this->radioButton_orders_number->UseVisualStyleBackColor = true;
			// 
			// radioButton_orders_pnumber
			// 
			this->radioButton_orders_pnumber->AutoSize = true;
			this->radioButton_orders_pnumber->Location = System::Drawing::Point(734, 457);
			this->radioButton_orders_pnumber->Name = L"radioButton_orders_pnumber";
			this->radioButton_orders_pnumber->Size = System::Drawing::Size(196, 24);
			this->radioButton_orders_pnumber->TabIndex = 61;
			this->radioButton_orders_pnumber->TabStop = true;
			this->radioButton_orders_pnumber->Text = L"По номеру телефона";
			this->radioButton_orders_pnumber->UseVisualStyleBackColor = true;
			// 
			// radioButton_orders_date
			// 
			this->radioButton_orders_date->AutoSize = true;
			this->radioButton_orders_date->Location = System::Drawing::Point(735, 487);
			this->radioButton_orders_date->Name = L"radioButton_orders_date";
			this->radioButton_orders_date->Size = System::Drawing::Size(152, 24);
			this->radioButton_orders_date->TabIndex = 60;
			this->radioButton_orders_date->TabStop = true;
			this->radioButton_orders_date->Text = L"По дате заказа";
			this->radioButton_orders_date->UseVisualStyleBackColor = true;
			// 
			// radioButton_orders_length
			// 
			this->radioButton_orders_length->AutoSize = true;
			this->radioButton_orders_length->Location = System::Drawing::Point(735, 517);
			this->radioButton_orders_length->Name = L"radioButton_orders_length";
			this->radioButton_orders_length->Size = System::Drawing::Size(225, 24);
			this->radioButton_orders_length->TabIndex = 59;
			this->radioButton_orders_length->TabStop = true;
			this->radioButton_orders_length->Text = L"По длительности заказа";
			this->radioButton_orders_length->UseVisualStyleBackColor = true;
			// 
			// button_orders_length
			// 
			this->button_orders_length->Location = System::Drawing::Point(962, 587);
			this->button_orders_length->Name = L"button_orders_length";
			this->button_orders_length->Size = System::Drawing::Size(227, 34);
			this->button_orders_length->TabIndex = 53;
			this->button_orders_length->Text = L"Дерево по длительности";
			this->button_orders_length->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageBeforeText;
			this->button_orders_length->UseVisualStyleBackColor = true;
			this->button_orders_length->Click += gcnew System::EventHandler(this, &Main::button_orders_length_Click);
			// 
			// comboBox_orders_length
			// 
			this->comboBox_orders_length->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->comboBox_orders_length->FormattingEnabled = true;
			this->comboBox_orders_length->Items->AddRange(gcnew cli::array< System::Object^  >(24) {
				L"1", L"2", L"3", L"4", L"5", L"6",
					L"7", L"8", L"9", L"10", L"11", L"12", L"13", L"14", L"15", L"16", L"17", L"18", L"19", L"20", L"21", L"22", L"23", L"24"
			});
			this->comboBox_orders_length->Location = System::Drawing::Point(315, 548);
			this->comboBox_orders_length->MaxDropDownItems = 24;
			this->comboBox_orders_length->Name = L"comboBox_orders_length";
			this->comboBox_orders_length->Size = System::Drawing::Size(121, 28);
			this->comboBox_orders_length->TabIndex = 52;
			// 
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->Location = System::Drawing::Point(68, 517);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(103, 20);
			this->label13->TabIndex = 50;
			this->label13->Text = L"Дата заказа";
			this->label13->Click += gcnew System::EventHandler(this, &Main::label13_Click);
			// 
			// textBox_orders_pnum
			// 
			this->textBox_orders_pnum->Location = System::Drawing::Point(305, 470);
			this->textBox_orders_pnum->Name = L"textBox_orders_pnum";
			this->textBox_orders_pnum->Size = System::Drawing::Size(164, 26);
			this->textBox_orders_pnum->TabIndex = 47;
			this->textBox_orders_pnum->TextChanged += gcnew System::EventHandler(this, &Main::textBox_orders_pnum_TextChanged);
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Location = System::Drawing::Point(267, 470);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(36, 20);
			this->label12->TabIndex = 46;
			this->label12->Text = L"+79";
			// 
			// label19
			// 
			this->label19->AutoSize = true;
			this->label19->Location = System::Drawing::Point(311, 437);
			this->label19->Name = L"label19";
			this->label19->Size = System::Drawing::Size(142, 20);
			this->label19->TabIndex = 45;
			this->label19->Text = L"Номер телефона";
			// 
			// button_orders_date
			// 
			this->button_orders_date->Location = System::Drawing::Point(962, 545);
			this->button_orders_date->Name = L"button_orders_date";
			this->button_orders_date->Size = System::Drawing::Size(227, 34);
			this->button_orders_date->TabIndex = 42;
			this->button_orders_date->Text = L"Дерево по дате заказа";
			this->button_orders_date->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageBeforeText;
			this->button_orders_date->UseVisualStyleBackColor = true;
			this->button_orders_date->Click += gcnew System::EventHandler(this, &Main::button_orders_date_Click);
			// 
			// button_orders_number
			// 
			this->button_orders_number->Location = System::Drawing::Point(962, 462);
			this->button_orders_number->Name = L"button_orders_number";
			this->button_orders_number->Size = System::Drawing::Size(227, 34);
			this->button_orders_number->TabIndex = 41;
			this->button_orders_number->Text = L"Дерево по госномеру";
			this->button_orders_number->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageBeforeText;
			this->button_orders_number->UseVisualStyleBackColor = true;
			this->button_orders_number->Click += gcnew System::EventHandler(this, &Main::button_orders_number_Click);
			// 
			// button_orders_HT
			// 
			this->button_orders_HT->Location = System::Drawing::Point(962, 422);
			this->button_orders_HT->Name = L"button_orders_HT";
			this->button_orders_HT->Size = System::Drawing::Size(227, 34);
			this->button_orders_HT->TabIndex = 40;
			this->button_orders_HT->Text = L"Хеш-таблица";
			this->button_orders_HT->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageBeforeText;
			this->button_orders_HT->UseVisualStyleBackColor = true;
			this->button_orders_HT->Click += gcnew System::EventHandler(this, &Main::button_orders_HT_Click);
			// 
			// button_orders_pnumber
			// 
			this->button_orders_pnumber->Location = System::Drawing::Point(962, 502);
			this->button_orders_pnumber->Name = L"button_orders_pnumber";
			this->button_orders_pnumber->Size = System::Drawing::Size(227, 34);
			this->button_orders_pnumber->TabIndex = 39;
			this->button_orders_pnumber->Text = L"Дерево по телефону";
			this->button_orders_pnumber->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageBeforeText;
			this->button_orders_pnumber->UseVisualStyleBackColor = true;
			this->button_orders_pnumber->Click += gcnew System::EventHandler(this, &Main::button_orders_pnumber_Click);
			// 
			// button_orders_delete
			// 
			this->button_orders_delete->Location = System::Drawing::Point(486, 517);
			this->button_orders_delete->Name = L"button_orders_delete";
			this->button_orders_delete->Size = System::Drawing::Size(114, 45);
			this->button_orders_delete->TabIndex = 36;
			this->button_orders_delete->Text = L"Удалить";
			this->button_orders_delete->UseVisualStyleBackColor = true;
			this->button_orders_delete->Click += gcnew System::EventHandler(this, &Main::button_orders_delete_Click);
			// 
			// button_orders_find
			// 
			this->button_orders_find->Location = System::Drawing::Point(767, 571);
			this->button_orders_find->Name = L"button_orders_find";
			this->button_orders_find->Size = System::Drawing::Size(114, 45);
			this->button_orders_find->TabIndex = 35;
			this->button_orders_find->Text = L"Найти";
			this->button_orders_find->UseVisualStyleBackColor = true;
			this->button_orders_find->Click += gcnew System::EventHandler(this, &Main::button_orders_find_Click);
			// 
			// button_orders_add
			// 
			this->button_orders_add->Location = System::Drawing::Point(486, 451);
			this->button_orders_add->Name = L"button_orders_add";
			this->button_orders_add->Size = System::Drawing::Size(114, 45);
			this->button_orders_add->TabIndex = 34;
			this->button_orders_add->Text = L"Добавить";
			this->button_orders_add->UseVisualStyleBackColor = true;
			this->button_orders_add->Click += gcnew System::EventHandler(this, &Main::button_orders_add_Click);
			// 
			// label14
			// 
			this->label14->AutoSize = true;
			this->label14->Location = System::Drawing::Point(293, 519);
			this->label14->Name = L"label14";
			this->label14->Size = System::Drawing::Size(176, 20);
			this->label14->TabIndex = 31;
			this->label14->Text = L"Длительность заказа";
			// 
			// label15
			// 
			this->label15->AutoSize = true;
			this->label15->Location = System::Drawing::Point(68, 447);
			this->label15->Name = L"label15";
			this->label15->Size = System::Drawing::Size(82, 20);
			this->label15->TabIndex = 30;
			this->label15->Text = L"Госномер";
			// 
			// textBox_orders_num
			// 
			this->textBox_orders_num->Location = System::Drawing::Point(65, 470);
			this->textBox_orders_num->Name = L"textBox_orders_num";
			this->textBox_orders_num->Size = System::Drawing::Size(86, 26);
			this->textBox_orders_num->TabIndex = 26;
			this->textBox_orders_num->TextChanged += gcnew System::EventHandler(this, &Main::textBox_orders_num_TextChanged);
			// 
			// textBox_orders_2letter
			// 
			this->textBox_orders_2letter->Location = System::Drawing::Point(157, 470);
			this->textBox_orders_2letter->Name = L"textBox_orders_2letter";
			this->textBox_orders_2letter->Size = System::Drawing::Size(68, 26);
			this->textBox_orders_2letter->TabIndex = 25;
			this->textBox_orders_2letter->TextChanged += gcnew System::EventHandler(this, &Main::textBox_orders_2letter_TextChanged);
			// 
			// textBox_orders_1letterr
			// 
			this->textBox_orders_1letterr->Location = System::Drawing::Point(11, 470);
			this->textBox_orders_1letterr->Name = L"textBox_orders_1letterr";
			this->textBox_orders_1letterr->Size = System::Drawing::Size(48, 26);
			this->textBox_orders_1letterr->TabIndex = 24;
			this->textBox_orders_1letterr->TextChanged += gcnew System::EventHandler(this, &Main::textBox_orders_1letterr_TextChanged);
			// 
			// richTextBox_orders_data
			// 
			this->richTextBox_orders_data->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->richTextBox_orders_data->Location = System::Drawing::Point(8, 28);
			this->richTextBox_orders_data->Name = L"richTextBox_orders_data";
			this->richTextBox_orders_data->ReadOnly = true;
			this->richTextBox_orders_data->Size = System::Drawing::Size(583, 395);
			this->richTextBox_orders_data->TabIndex = 23;
			this->richTextBox_orders_data->Text = L"";
			// 
			// richTextBox_orders_structure
			// 
			this->richTextBox_orders_structure->Location = System::Drawing::Point(621, 28);
			this->richTextBox_orders_structure->Name = L"richTextBox_orders_structure";
			this->richTextBox_orders_structure->ReadOnly = true;
			this->richTextBox_orders_structure->Size = System::Drawing::Size(583, 395);
			this->richTextBox_orders_structure->TabIndex = 22;
			this->richTextBox_orders_structure->Text = L"";
			// 
			// tabPage_clients
			// 
			this->tabPage_clients->Controls->Add(this->textBox_clients_db);
			this->tabPage_clients->Controls->Add(this->button_clients_export);
			this->tabPage_clients->Controls->Add(this->button_clietns_import);
			this->tabPage_clients->Controls->Add(this->radioButton_clients_adress);
			this->tabPage_clients->Controls->Add(this->radioButton_clients_num);
			this->tabPage_clients->Controls->Add(this->radioButton_clients_DB);
			this->tabPage_clients->Controls->Add(this->radioButton_clients_FIO);
			this->tabPage_clients->Controls->Add(this->button8);
			this->tabPage_clients->Controls->Add(this->button9);
			this->tabPage_clients->Controls->Add(this->button10);
			this->tabPage_clients->Controls->Add(this->button11);
			this->tabPage_clients->Controls->Add(this->textBox_clients_name);
			this->tabPage_clients->Controls->Add(this->textBox_clients_lastname);
			this->tabPage_clients->Controls->Add(this->label18);
			this->tabPage_clients->Controls->Add(this->label17);
			this->tabPage_clients->Controls->Add(this->textBox_clients_num);
			this->tabPage_clients->Controls->Add(this->label16);
			this->tabPage_clients->Controls->Add(this->textBox_clients_size_HT);
			this->tabPage_clients->Controls->Add(this->label6);
			this->tabPage_clients->Controls->Add(this->button12);
			this->tabPage_clients->Controls->Add(this->button13);
			this->tabPage_clients->Controls->Add(this->button14);
			this->tabPage_clients->Controls->Add(this->label7);
			this->tabPage_clients->Controls->Add(this->label8);
			this->tabPage_clients->Controls->Add(this->label9);
			this->tabPage_clients->Controls->Add(this->label10);
			this->tabPage_clients->Controls->Add(this->textBox_clients_address);
			this->tabPage_clients->Controls->Add(this->textBox_clients_surname);
			this->tabPage_clients->Controls->Add(this->richTextBox_clients_data);
			this->tabPage_clients->Controls->Add(this->richTextBox_clients_structure);
			this->tabPage_clients->Location = System::Drawing::Point(4, 29);
			this->tabPage_clients->Name = L"tabPage_clients";
			this->tabPage_clients->Padding = System::Windows::Forms::Padding(3);
			this->tabPage_clients->Size = System::Drawing::Size(1208, 622);
			this->tabPage_clients->TabIndex = 1;
			this->tabPage_clients->Text = L"Клиенты";
			this->tabPage_clients->UseVisualStyleBackColor = true;
			this->tabPage_clients->Click += gcnew System::EventHandler(this, &Main::tabPage_clients_Click);
			// 
			// textBox_clients_db
			// 
			this->textBox_clients_db->Location = System::Drawing::Point(312, 467);
			this->textBox_clients_db->Name = L"textBox_clients_db";
			this->textBox_clients_db->Size = System::Drawing::Size(124, 26);
			this->textBox_clients_db->TabIndex = 60;
			this->textBox_clients_db->TextChanged += gcnew System::EventHandler(this, &Main::textBox_clients_db_TextChanged);
			// 
			// button_clients_export
			// 
			this->button_clients_export->Location = System::Drawing::Point(926, 517);
			this->button_clients_export->Name = L"button_clients_export";
			this->button_clients_export->Size = System::Drawing::Size(101, 42);
			this->button_clients_export->TabIndex = 59;
			this->button_clients_export->Text = L"Экспорт";
			this->button_clients_export->UseVisualStyleBackColor = true;
			this->button_clients_export->Click += gcnew System::EventHandler(this, &Main::button_clients_export_Click);
			// 
			// button_clietns_import
			// 
			this->button_clietns_import->Location = System::Drawing::Point(926, 460);
			this->button_clietns_import->Name = L"button_clietns_import";
			this->button_clietns_import->Size = System::Drawing::Size(101, 44);
			this->button_clietns_import->TabIndex = 58;
			this->button_clietns_import->Text = L"Импорт";
			this->button_clietns_import->UseVisualStyleBackColor = true;
			this->button_clietns_import->Click += gcnew System::EventHandler(this, &Main::button_clietns_import_Click);
			// 
			// radioButton_clients_adress
			// 
			this->radioButton_clients_adress->AutoSize = true;
			this->radioButton_clients_adress->Location = System::Drawing::Point(779, 436);
			this->radioButton_clients_adress->Name = L"radioButton_clients_adress";
			this->radioButton_clients_adress->Size = System::Drawing::Size(112, 24);
			this->radioButton_clients_adress->TabIndex = 57;
			this->radioButton_clients_adress->TabStop = true;
			this->radioButton_clients_adress->Text = L"По адресу";
			this->radioButton_clients_adress->UseVisualStyleBackColor = true;
			// 
			// radioButton_clients_num
			// 
			this->radioButton_clients_num->AutoSize = true;
			this->radioButton_clients_num->Location = System::Drawing::Point(778, 466);
			this->radioButton_clients_num->Name = L"radioButton_clients_num";
			this->radioButton_clients_num->Size = System::Drawing::Size(113, 24);
			this->radioButton_clients_num->TabIndex = 56;
			this->radioButton_clients_num->TabStop = true;
			this->radioButton_clients_num->Text = L"По номеру";
			this->radioButton_clients_num->UseVisualStyleBackColor = true;
			// 
			// radioButton_clients_DB
			// 
			this->radioButton_clients_DB->AutoSize = true;
			this->radioButton_clients_DB->Location = System::Drawing::Point(779, 496);
			this->radioButton_clients_DB->Name = L"radioButton_clients_DB";
			this->radioButton_clients_DB->Size = System::Drawing::Size(135, 24);
			this->radioButton_clients_DB->TabIndex = 55;
			this->radioButton_clients_DB->TabStop = true;
			this->radioButton_clients_DB->Text = L"По дню рожд";
			this->radioButton_clients_DB->UseVisualStyleBackColor = true;
			// 
			// radioButton_clients_FIO
			// 
			this->radioButton_clients_FIO->AutoSize = true;
			this->radioButton_clients_FIO->Location = System::Drawing::Point(779, 526);
			this->radioButton_clients_FIO->Name = L"radioButton_clients_FIO";
			this->radioButton_clients_FIO->Size = System::Drawing::Size(97, 24);
			this->radioButton_clients_FIO->TabIndex = 54;
			this->radioButton_clients_FIO->TabStop = true;
			this->radioButton_clients_FIO->Text = L"По ФИО";
			this->radioButton_clients_FIO->UseVisualStyleBackColor = true;
			// 
			// button8
			// 
			this->button8->Location = System::Drawing::Point(1033, 553);
			this->button8->Name = L"button8";
			this->button8->Size = System::Drawing::Size(169, 34);
			this->button8->TabIndex = 53;
			this->button8->Text = L"Дерево по адресу";
			this->button8->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageBeforeText;
			this->button8->UseVisualStyleBackColor = true;
			this->button8->Click += gcnew System::EventHandler(this, &Main::button8_Click);
			// 
			// button9
			// 
			this->button9->Location = System::Drawing::Point(1033, 470);
			this->button9->Name = L"button9";
			this->button9->Size = System::Drawing::Size(169, 34);
			this->button9->TabIndex = 52;
			this->button9->Text = L"Дерево по ФИО";
			this->button9->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageBeforeText;
			this->button9->UseVisualStyleBackColor = true;
			this->button9->Click += gcnew System::EventHandler(this, &Main::button9_Click);
			// 
			// button10
			// 
			this->button10->Location = System::Drawing::Point(1033, 430);
			this->button10->Name = L"button10";
			this->button10->Size = System::Drawing::Size(169, 34);
			this->button10->TabIndex = 51;
			this->button10->Text = L"Хеш-таблица";
			this->button10->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageBeforeText;
			this->button10->UseVisualStyleBackColor = true;
			this->button10->Click += gcnew System::EventHandler(this, &Main::button10_Click);
			// 
			// button11
			// 
			this->button11->Location = System::Drawing::Point(1033, 510);
			this->button11->Name = L"button11";
			this->button11->Size = System::Drawing::Size(169, 34);
			this->button11->TabIndex = 50;
			this->button11->Text = L"Дерево по др";
			this->button11->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageBeforeText;
			this->button11->UseVisualStyleBackColor = true;
			this->button11->Click += gcnew System::EventHandler(this, &Main::button11_Click);
			// 
			// textBox_clients_name
			// 
			this->textBox_clients_name->Location = System::Drawing::Point(295, 545);
			this->textBox_clients_name->Name = L"textBox_clients_name";
			this->textBox_clients_name->Size = System::Drawing::Size(164, 26);
			this->textBox_clients_name->TabIndex = 48;
			this->textBox_clients_name->TextChanged += gcnew System::EventHandler(this, &Main::textBox_clients_name_TextChanged);
			// 
			// textBox_clients_lastname
			// 
			this->textBox_clients_lastname->Location = System::Drawing::Point(465, 545);
			this->textBox_clients_lastname->Name = L"textBox_clients_lastname";
			this->textBox_clients_lastname->Size = System::Drawing::Size(164, 26);
			this->textBox_clients_lastname->TabIndex = 47;
			this->textBox_clients_lastname->TextChanged += gcnew System::EventHandler(this, &Main::textBox_clients_lastname_TextChanged);
			// 
			// label18
			// 
			this->label18->AutoSize = true;
			this->label18->Location = System::Drawing::Point(493, 509);
			this->label18->Name = L"label18";
			this->label18->Size = System::Drawing::Size(83, 20);
			this->label18->TabIndex = 46;
			this->label18->Text = L"Отчество";
			// 
			// label17
			// 
			this->label17->AutoSize = true;
			this->label17->Location = System::Drawing::Point(322, 509);
			this->label17->Name = L"label17";
			this->label17->Size = System::Drawing::Size(40, 20);
			this->label17->TabIndex = 45;
			this->label17->Text = L"Имя";
			// 
			// textBox_clients_num
			// 
			this->textBox_clients_num->Location = System::Drawing::Point(125, 466);
			this->textBox_clients_num->Name = L"textBox_clients_num";
			this->textBox_clients_num->Size = System::Drawing::Size(164, 26);
			this->textBox_clients_num->TabIndex = 44;
			this->textBox_clients_num->TextChanged += gcnew System::EventHandler(this, &Main::textBox_clients_num_TextChanged);
			// 
			// label16
			// 
			this->label16->AutoSize = true;
			this->label16->Location = System::Drawing::Point(83, 471);
			this->label16->Name = L"label16";
			this->label16->Size = System::Drawing::Size(36, 20);
			this->label16->TabIndex = 43;
			this->label16->Text = L"+79";
			// 
			// textBox_clients_size_HT
			// 
			this->textBox_clients_size_HT->Location = System::Drawing::Point(10, 545);
			this->textBox_clients_size_HT->Name = L"textBox_clients_size_HT";
			this->textBox_clients_size_HT->Size = System::Drawing::Size(53, 26);
			this->textBox_clients_size_HT->TabIndex = 38;
			this->textBox_clients_size_HT->TextChanged += gcnew System::EventHandler(this, &Main::textBox8_TextChanged);
			// 
			// label6
			// 
			this->label6->AutoEllipsis = true;
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(6, 496);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(109, 40);
			this->label6->TabIndex = 37;
			this->label6->Text = L"Размер \r\nхеш-таблицы";
			// 
			// button12
			// 
			this->button12->Location = System::Drawing::Point(635, 536);
			this->button12->Name = L"button12";
			this->button12->Size = System::Drawing::Size(114, 45);
			this->button12->TabIndex = 36;
			this->button12->Text = L"Удалить";
			this->button12->UseVisualStyleBackColor = true;
			this->button12->Click += gcnew System::EventHandler(this, &Main::button12_Click);
			// 
			// button13
			// 
			this->button13->Location = System::Drawing::Point(779, 556);
			this->button13->Name = L"button13";
			this->button13->Size = System::Drawing::Size(114, 45);
			this->button13->TabIndex = 35;
			this->button13->Text = L"Найти";
			this->button13->UseVisualStyleBackColor = true;
			this->button13->Click += gcnew System::EventHandler(this, &Main::button13_Click);
			// 
			// button14
			// 
			this->button14->Location = System::Drawing::Point(635, 459);
			this->button14->Name = L"button14";
			this->button14->Size = System::Drawing::Size(114, 45);
			this->button14->TabIndex = 34;
			this->button14->Text = L"Добавить";
			this->button14->UseVisualStyleBackColor = true;
			this->button14->Click += gcnew System::EventHandler(this, &Main::button14_Click);
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(137, 509);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(81, 20);
			this->label7->TabIndex = 33;
			this->label7->Text = L"Фамилия";
			this->label7->Click += gcnew System::EventHandler(this, &Main::label7_Click);
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(308, 433);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(128, 20);
			this->label8->TabIndex = 32;
			this->label8->Text = L"Дата рождения";
			this->label8->Click += gcnew System::EventHandler(this, &Main::label8_Click);
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(493, 433);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(57, 20);
			this->label9->TabIndex = 31;
			this->label9->Text = L"Адрес";
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Location = System::Drawing::Point(137, 430);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(142, 20);
			this->label10->TabIndex = 30;
			this->label10->Text = L"Номер телефона";
			this->label10->Click += gcnew System::EventHandler(this, &Main::label10_Click);
			// 
			// textBox_clients_address
			// 
			this->textBox_clients_address->Location = System::Drawing::Point(465, 467);
			this->textBox_clients_address->Name = L"textBox_clients_address";
			this->textBox_clients_address->Size = System::Drawing::Size(164, 26);
			this->textBox_clients_address->TabIndex = 29;
			this->textBox_clients_address->TextChanged += gcnew System::EventHandler(this, &Main::textBox_clients_address_TextChanged);
			// 
			// textBox_clients_surname
			// 
			this->textBox_clients_surname->Location = System::Drawing::Point(125, 545);
			this->textBox_clients_surname->Name = L"textBox_clients_surname";
			this->textBox_clients_surname->Size = System::Drawing::Size(164, 26);
			this->textBox_clients_surname->TabIndex = 28;
			this->textBox_clients_surname->TextChanged += gcnew System::EventHandler(this, &Main::textBox_clients_surname_TextChanged);
			// 
			// richTextBox_clients_data
			// 
			this->richTextBox_clients_data->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->richTextBox_clients_data->Location = System::Drawing::Point(8, 28);
			this->richTextBox_clients_data->Name = L"richTextBox_clients_data";
			this->richTextBox_clients_data->ReadOnly = true;
			this->richTextBox_clients_data->Size = System::Drawing::Size(583, 395);
			this->richTextBox_clients_data->TabIndex = 23;
			this->richTextBox_clients_data->Text = L"";
			// 
			// richTextBox_clients_structure
			// 
			this->richTextBox_clients_structure->Location = System::Drawing::Point(621, 28);
			this->richTextBox_clients_structure->Name = L"richTextBox_clients_structure";
			this->richTextBox_clients_structure->ReadOnly = true;
			this->richTextBox_clients_structure->Size = System::Drawing::Size(583, 395);
			this->richTextBox_clients_structure->TabIndex = 22;
			this->richTextBox_clients_structure->Text = L"";
			// 
			// tabPage_cars
			// 
			this->tabPage_cars->Controls->Add(this->radioButton_cars_color);
			this->tabPage_cars->Controls->Add(this->radioButton_cars_model);
			this->tabPage_cars->Controls->Add(this->radioButton_cars_brand);
			this->tabPage_cars->Controls->Add(this->radioButton_cars_label);
			this->tabPage_cars->Controls->Add(this->button_export);
			this->tabPage_cars->Controls->Add(this->button_import);
			this->tabPage_cars->Controls->Add(this->button_cars_trees_color);
			this->tabPage_cars->Controls->Add(this->button_cars_tree_brand);
			this->tabPage_cars->Controls->Add(this->button_cars_hashtable);
			this->tabPage_cars->Controls->Add(this->button_cars_tree_model);
			this->tabPage_cars->Controls->Add(this->textBox_car_size_HT);
			this->tabPage_cars->Controls->Add(this->label5);
			this->tabPage_cars->Controls->Add(this->button_delete_cars);
			this->tabPage_cars->Controls->Add(this->button_find_cars);
			this->tabPage_cars->Controls->Add(this->button_add_cars);
			this->tabPage_cars->Controls->Add(this->label4);
			this->tabPage_cars->Controls->Add(this->label3);
			this->tabPage_cars->Controls->Add(this->label2);
			this->tabPage_cars->Controls->Add(this->label1);
			this->tabPage_cars->Controls->Add(this->textBox_car_color);
			this->tabPage_cars->Controls->Add(this->textBox_car_brand);
			this->tabPage_cars->Controls->Add(this->textBox_car_model);
			this->tabPage_cars->Controls->Add(this->textBox_car_num);
			this->tabPage_cars->Controls->Add(this->textBox_car_2letter);
			this->tabPage_cars->Controls->Add(this->textBox_car_1letter);
			this->tabPage_cars->Controls->Add(this->richTextBox_cars_data);
			this->tabPage_cars->Controls->Add(this->richTextBox_cars_structure);
			this->tabPage_cars->Location = System::Drawing::Point(4, 29);
			this->tabPage_cars->Name = L"tabPage_cars";
			this->tabPage_cars->Padding = System::Windows::Forms::Padding(3);
			this->tabPage_cars->Size = System::Drawing::Size(1208, 622);
			this->tabPage_cars->TabIndex = 0;
			this->tabPage_cars->Text = L"Автомобили";
			this->tabPage_cars->UseVisualStyleBackColor = true;
			this->tabPage_cars->Click += gcnew System::EventHandler(this, &Main::tabPage1_Click);
			// 
			// radioButton_cars_color
			// 
			this->radioButton_cars_color->AutoSize = true;
			this->radioButton_cars_color->Location = System::Drawing::Point(690, 514);
			this->radioButton_cars_color->Name = L"radioButton_cars_color";
			this->radioButton_cars_color->Size = System::Drawing::Size(102, 24);
			this->radioButton_cars_color->TabIndex = 27;
			this->radioButton_cars_color->TabStop = true;
			this->radioButton_cars_color->Text = L"По цвету";
			this->radioButton_cars_color->UseVisualStyleBackColor = true;
			// 
			// radioButton_cars_model
			// 
			this->radioButton_cars_model->AutoSize = true;
			this->radioButton_cars_model->Location = System::Drawing::Point(690, 483);
			this->radioButton_cars_model->Name = L"radioButton_cars_model";
			this->radioButton_cars_model->Size = System::Drawing::Size(118, 24);
			this->radioButton_cars_model->TabIndex = 26;
			this->radioButton_cars_model->TabStop = true;
			this->radioButton_cars_model->Text = L"По модели";
			this->radioButton_cars_model->UseVisualStyleBackColor = true;
			// 
			// radioButton_cars_brand
			// 
			this->radioButton_cars_brand->AutoSize = true;
			this->radioButton_cars_brand->Location = System::Drawing::Point(690, 452);
			this->radioButton_cars_brand->Name = L"radioButton_cars_brand";
			this->radioButton_cars_brand->Size = System::Drawing::Size(105, 24);
			this->radioButton_cars_brand->TabIndex = 25;
			this->radioButton_cars_brand->TabStop = true;
			this->radioButton_cars_brand->Text = L"По марке";
			this->radioButton_cars_brand->UseVisualStyleBackColor = true;
			// 
			// radioButton_cars_label
			// 
			this->radioButton_cars_label->AutoSize = true;
			this->radioButton_cars_label->Location = System::Drawing::Point(690, 421);
			this->radioButton_cars_label->Name = L"radioButton_cars_label";
			this->radioButton_cars_label->Size = System::Drawing::Size(137, 24);
			this->radioButton_cars_label->TabIndex = 24;
			this->radioButton_cars_label->TabStop = true;
			this->radioButton_cars_label->Text = L"По госномеру";
			this->radioButton_cars_label->UseVisualStyleBackColor = true;
			// 
			// button_export
			// 
			this->button_export->Location = System::Drawing::Point(855, 504);
			this->button_export->Name = L"button_export";
			this->button_export->Size = System::Drawing::Size(114, 45);
			this->button_export->TabIndex = 23;
			this->button_export->Text = L"Экспорт";
			this->button_export->UseVisualStyleBackColor = true;
			this->button_export->Click += gcnew System::EventHandler(this, &Main::button_export_Click);
			// 
			// button_import
			// 
			this->button_import->Location = System::Drawing::Point(855, 453);
			this->button_import->Name = L"button_import";
			this->button_import->Size = System::Drawing::Size(114, 45);
			this->button_import->TabIndex = 22;
			this->button_import->Text = L"Импорт";
			this->button_import->UseVisualStyleBackColor = true;
			this->button_import->Click += gcnew System::EventHandler(this, &Main::button_import_Click);
			// 
			// button_cars_trees_color
			// 
			this->button_cars_trees_color->Location = System::Drawing::Point(975, 548);
			this->button_cars_trees_color->Name = L"button_cars_trees_color";
			this->button_cars_trees_color->Size = System::Drawing::Size(227, 34);
			this->button_cars_trees_color->TabIndex = 21;
			this->button_cars_trees_color->Text = L"Дерево по цвету";
			this->button_cars_trees_color->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageBeforeText;
			this->button_cars_trees_color->UseVisualStyleBackColor = true;
			this->button_cars_trees_color->Click += gcnew System::EventHandler(this, &Main::button_cars_trees_color_Click);
			// 
			// button_cars_tree_brand
			// 
			this->button_cars_tree_brand->Location = System::Drawing::Point(975, 468);
			this->button_cars_tree_brand->Name = L"button_cars_tree_brand";
			this->button_cars_tree_brand->Size = System::Drawing::Size(227, 34);
			this->button_cars_tree_brand->TabIndex = 20;
			this->button_cars_tree_brand->Text = L"Дерево по марке";
			this->button_cars_tree_brand->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageBeforeText;
			this->button_cars_tree_brand->UseVisualStyleBackColor = true;
			this->button_cars_tree_brand->Click += gcnew System::EventHandler(this, &Main::button_cars_tree_brand_Click);
			// 
			// button_cars_hashtable
			// 
			this->button_cars_hashtable->Location = System::Drawing::Point(975, 428);
			this->button_cars_hashtable->Name = L"button_cars_hashtable";
			this->button_cars_hashtable->Size = System::Drawing::Size(227, 34);
			this->button_cars_hashtable->TabIndex = 19;
			this->button_cars_hashtable->Text = L"Хеш-таблица";
			this->button_cars_hashtable->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageBeforeText;
			this->button_cars_hashtable->UseVisualStyleBackColor = true;
			this->button_cars_hashtable->Click += gcnew System::EventHandler(this, &Main::button_cars_hashtable_Click);
			// 
			// button_cars_tree_model
			// 
			this->button_cars_tree_model->Location = System::Drawing::Point(975, 508);
			this->button_cars_tree_model->Name = L"button_cars_tree_model";
			this->button_cars_tree_model->Size = System::Drawing::Size(227, 34);
			this->button_cars_tree_model->TabIndex = 18;
			this->button_cars_tree_model->Text = L"Дерево по модели";
			this->button_cars_tree_model->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageBeforeText;
			this->button_cars_tree_model->UseVisualStyleBackColor = true;
			this->button_cars_tree_model->Click += gcnew System::EventHandler(this, &Main::button_cars_tree_model_Click);
			// 
			// textBox_car_size_HT
			// 
			this->textBox_car_size_HT->Location = System::Drawing::Point(10, 503);
			this->textBox_car_size_HT->Name = L"textBox_car_size_HT";
			this->textBox_car_size_HT->Size = System::Drawing::Size(53, 26);
			this->textBox_car_size_HT->TabIndex = 17;
			this->textBox_car_size_HT->TextChanged += gcnew System::EventHandler(this, &Main::textBox_car_size_HT_TextChanged);
			// 
			// label5
			// 
			this->label5->AutoEllipsis = true;
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(2, 457);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(109, 40);
			this->label5->TabIndex = 16;
			this->label5->Text = L"Размер \r\nхеш-таблицы";
			// 
			// button_delete_cars
			// 
			this->button_delete_cars->Location = System::Drawing::Point(513, 438);
			this->button_delete_cars->Name = L"button_delete_cars";
			this->button_delete_cars->Size = System::Drawing::Size(114, 45);
			this->button_delete_cars->TabIndex = 14;
			this->button_delete_cars->Text = L"Удалить";
			this->button_delete_cars->UseVisualStyleBackColor = true;
			this->button_delete_cars->Click += gcnew System::EventHandler(this, &Main::button_delete_cars_Click);
			// 
			// button_find_cars
			// 
			this->button_find_cars->Location = System::Drawing::Point(690, 548);
			this->button_find_cars->Name = L"button_find_cars";
			this->button_find_cars->Size = System::Drawing::Size(114, 45);
			this->button_find_cars->TabIndex = 13;
			this->button_find_cars->Text = L"Найти";
			this->button_find_cars->UseVisualStyleBackColor = true;
			this->button_find_cars->Click += gcnew System::EventHandler(this, &Main::button_find_cars_Click);
			// 
			// button_add_cars
			// 
			this->button_add_cars->Location = System::Drawing::Point(513, 520);
			this->button_add_cars->Name = L"button_add_cars";
			this->button_add_cars->Size = System::Drawing::Size(114, 45);
			this->button_add_cars->TabIndex = 12;
			this->button_add_cars->Text = L"Добавить";
			this->button_add_cars->UseVisualStyleBackColor = true;
			this->button_add_cars->Click += gcnew System::EventHandler(this, &Main::button_add_cars_Click);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(391, 421);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(57, 20);
			this->label4->TabIndex = 11;
			this->label4->Text = L"Марка";
			this->label4->Click += gcnew System::EventHandler(this, &Main::label4_Click);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(181, 503);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(70, 20);
			this->label3->TabIndex = 10;
			this->label3->Text = L"Модель";
			this->label3->Click += gcnew System::EventHandler(this, &Main::label3_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(391, 503);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(48, 20);
			this->label2->TabIndex = 9;
			this->label2->Text = L"Цвет";
			this->label2->Click += gcnew System::EventHandler(this, &Main::label2_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(181, 421);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(82, 20);
			this->label1->TabIndex = 8;
			this->label1->Text = L"Госномер";
			this->label1->Click += gcnew System::EventHandler(this, &Main::label1_Click);
			// 
			// textBox_car_color
			// 
			this->textBox_car_color->Location = System::Drawing::Point(327, 539);
			this->textBox_car_color->Name = L"textBox_car_color";
			this->textBox_car_color->Size = System::Drawing::Size(164, 26);
			this->textBox_car_color->TabIndex = 7;
			this->textBox_car_color->TextChanged += gcnew System::EventHandler(this, &Main::textBox_car_color_TextChanged);
			// 
			// textBox_car_brand
			// 
			this->textBox_car_brand->Location = System::Drawing::Point(343, 457);
			this->textBox_car_brand->Name = L"textBox_car_brand";
			this->textBox_car_brand->Size = System::Drawing::Size(164, 26);
			this->textBox_car_brand->TabIndex = 6;
			this->textBox_car_brand->TextChanged += gcnew System::EventHandler(this, &Main::textBox_car_brand_TextChanged);
			// 
			// textBox_car_model
			// 
			this->textBox_car_model->Location = System::Drawing::Point(129, 539);
			this->textBox_car_model->Name = L"textBox_car_model";
			this->textBox_car_model->Size = System::Drawing::Size(164, 26);
			this->textBox_car_model->TabIndex = 5;
			this->textBox_car_model->TextChanged += gcnew System::EventHandler(this, &Main::textBox_car_model_TextChanged);
			// 
			// textBox_car_num
			// 
			this->textBox_car_num->Location = System::Drawing::Point(177, 457);
			this->textBox_car_num->Name = L"textBox_car_num";
			this->textBox_car_num->Size = System::Drawing::Size(86, 26);
			this->textBox_car_num->TabIndex = 4;
			this->textBox_car_num->TextChanged += gcnew System::EventHandler(this, &Main::textBox_car_num_TextChanged);
			// 
			// textBox_car_2letter
			// 
			this->textBox_car_2letter->Location = System::Drawing::Point(269, 457);
			this->textBox_car_2letter->Name = L"textBox_car_2letter";
			this->textBox_car_2letter->Size = System::Drawing::Size(68, 26);
			this->textBox_car_2letter->TabIndex = 3;
			this->textBox_car_2letter->TextChanged += gcnew System::EventHandler(this, &Main::textBox_car_2letter_TextChanged);
			// 
			// textBox_car_1letter
			// 
			this->textBox_car_1letter->Location = System::Drawing::Point(123, 457);
			this->textBox_car_1letter->Name = L"textBox_car_1letter";
			this->textBox_car_1letter->Size = System::Drawing::Size(48, 26);
			this->textBox_car_1letter->TabIndex = 2;
			this->textBox_car_1letter->TextChanged += gcnew System::EventHandler(this, &Main::textBox_car_1letter_TextChanged);
			// 
			// richTextBox_cars_data
			// 
			this->richTextBox_cars_data->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->richTextBox_cars_data->Location = System::Drawing::Point(6, 18);
			this->richTextBox_cars_data->Name = L"richTextBox_cars_data";
			this->richTextBox_cars_data->ReadOnly = true;
			this->richTextBox_cars_data->Size = System::Drawing::Size(583, 395);
			this->richTextBox_cars_data->TabIndex = 1;
			this->richTextBox_cars_data->Text = L"";
			// 
			// richTextBox_cars_structure
			// 
			this->richTextBox_cars_structure->Location = System::Drawing::Point(619, 18);
			this->richTextBox_cars_structure->Name = L"richTextBox_cars_structure";
			this->richTextBox_cars_structure->ReadOnly = true;
			this->richTextBox_cars_structure->Size = System::Drawing::Size(583, 395);
			this->richTextBox_cars_structure->TabIndex = 0;
			this->richTextBox_cars_structure->Text = L"";
			this->richTextBox_cars_structure->TextChanged += gcnew System::EventHandler(this, &Main::richTextBox1_TextChanged);
			// 
			// tabControl
			// 
			this->tabControl->Controls->Add(this->tabPage_cars);
			this->tabControl->Controls->Add(this->tabPage_clients);
			this->tabControl->Controls->Add(this->tabPage_orders);
			this->tabControl->Location = System::Drawing::Point(-2, 33);
			this->tabControl->Name = L"tabControl";
			this->tabControl->SelectedIndex = 0;
			this->tabControl->Size = System::Drawing::Size(1216, 655);
			this->tabControl->TabIndex = 1;
			// 
			// Main
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(195)), static_cast<System::Int32>(static_cast<System::Byte>(216)),
				static_cast<System::Int32>(static_cast<System::Byte>(179)));
			this->ClientSize = System::Drawing::Size(1217, 700);
			this->Controls->Add(this->button_exit);
			this->Controls->Add(this->tabControl);
			this->Cursor = System::Windows::Forms::Cursors::Default;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"Main";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"main";
			this->Load += gcnew System::EventHandler(this, &Main::Main_Load);
			this->tabPage_orders->ResumeLayout(false);
			this->tabPage_orders->PerformLayout();
			this->tabPage_clients->ResumeLayout(false);
			this->tabPage_clients->PerformLayout();
			this->tabPage_cars->ResumeLayout(false);
			this->tabPage_cars->PerformLayout();
			this->tabControl->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void Main_Load(System::Object^ sender, System::EventArgs^ e) {
	}

	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}

private: System::Void tabPage1_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void tabPage_clients_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void tabPage3_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void richTextBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void label3_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void label4_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void label2_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void button_cars_hashtable_Click(System::Object^ sender, System::EventArgs^ e) {

	richTextBox_cars_structure->Clear();
	String^ str = gcnew String(Hashtable->Print().data());
	richTextBox_cars_structure->AppendText(str);
}
private: System::Void button_cars_tree_model_Click(System::Object^ sender, System::EventArgs^ e) {

	richTextBox_cars_structure->Clear();
	String^ str = gcnew String(print(TreeModal).data());
	richTextBox_cars_structure->AppendText(str);
}
private: System::Void button_cars_tree_brand_Click(System::Object^ sender, System::EventArgs^ e) {

	richTextBox_cars_structure->Clear();
	String^ str = gcnew String(print(TreeBrand).data());
	richTextBox_cars_structure->AppendText(str);
}
private: System::Void label10_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void label8_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void label7_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void label13_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void button_import_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (importD &&!import && (textBox_car_size_HT->Text != "") && (Convert::ToInt32(textBox_car_size_HT->Text) > 0)) {

		richTextBox_cars_data->Clear();
		auto reader = System::IO::File::OpenText("Автомобили.txt");
		Hashtable = new HT(HashTable_size);


		import = true;
		int size = 0;
		while (!reader->EndOfStream) {
			auto str = reader->ReadLine();
			auto _list = str->Split(' ');
			richTextBox_cars_data->AppendText(str);
			if (_list->GetLength(0) == 6)
				_list[3] += " " + _list[4] + " " + _list[5];
			if (_list->GetLength(0) == 5)
				_list[3] += " " + _list[4];

			list* el = new list();

			msclr::interop::marshal_context context;
			el->color = context.marshal_as<std::string>(_list[3]);
			el->label = context.marshal_as<std::string>(_list[1]);
			el->model = context.marshal_as<std::string>(_list[2]);
			el->plate = context.marshal_as<std::string>(_list[0]);
			el->num = size;

			Add(el->label, size, TreeBrand);
			Add(el->color, size, TreeColor);
			Add(el->model, size, TreeModal);
			Hashtable->Add(*el);

			Record_cars.push_back(el);

			richTextBox_cars_data->AppendText("\n");
			++size;
		}
		reader->Close();
	}
}
private: System::Void button_cars_trees_color_Click(System::Object^ sender, System::EventArgs^ e) {

	richTextBox_cars_structure->Clear();
	String^ str = gcnew String(print(TreeColor).data());
	richTextBox_cars_structure->AppendText(str);
}
private: System::Void button_export_Click(System::Object^ sender, System::EventArgs^ e) {

	if (Hashtable->count == 0) {
		MessageBox::Show(this, "Вы не импортировали данные. Данное действие сотрёт данные из исходного файла.", "Error", MessageBoxButtons::OK);
	}
	else {
		{
			if (import) {
				auto vec = std::vector<list*>(0);
				for (auto i = Record_cars.size(); i > 0; --i) {
					if (Record_cars.back()) {
						vec.push_back(Record_cars.back());
						Record_cars.pop_back();
					}
				}
				System::IO::StreamWriter^ sw = gcnew System::IO::StreamWriter("Автомобили.txt");
				int s = vec.size();
				for (auto i = 0; i < s; ++i) {
					list* cur = vec.back();
					 vec.pop_back();
					String^ str = gcnew String((cur->plate + " " + cur->label + " " + cur->model + " " + cur->color).data());
					sw->WriteLine(str);
				}
				sw->Close();
				import = false;
			}
		}
	}
}
private: System::Void textBox_car_size_HT_TextChanged(System::Object^ sender, System::EventArgs^ e) {

	if ((textBox_car_size_HT->Text != " ")&&(textBox_car_size_HT->Text != "")) {

		if (System::Text::RegularExpressions::Regex::IsMatch(textBox_car_size_HT->Text, "[^0-9]")) {
			MessageBox::Show("В данное поле можно вводить только цифры.");
			textBox_car_size_HT->Clear();
		}
		else {
			if (Convert::ToInt16(textBox_car_size_HT->Text) <= 0) {
				MessageBox::Show("Размер таблицы не может быть не положительным числом.");
				textBox_car_size_HT->Clear();
			}
			else {

				HashTable_size = Convert::ToInt16(textBox_car_size_HT->Text);

				auto records = Record_cars;
				auto Hashtable2 = new HT(HashTable_size);
				int s = 0;
				for (auto i : records) {
					Hashtable2->Add(list(i->plate, i->label, i->model, i->color, s));
					s++;
				}
				Hashtable = Hashtable2;
			}
		}
	}
	else {
		textBox_car_size_HT->Clear();
	}
}
private: System::Void textBox_car_1letter_TextChanged(System::Object^ sender, System::EventArgs^ e) {

	if (Convert::ToString(textBox_car_1letter->Text)->Length > 1) {
		MessageBox::Show("Эта часть номера состоит из 1 буквы.");
		textBox_car_1letter->Clear();
	}
	else  if (Convert::ToString(textBox_car_1letter->Text)->Length > 0){
		bool check = false;
		unsigned char ch = Convert::ToString(textBox_car_1letter->Text)[0];
		for (int i = 0; CarNum.length() > i; ++i) {
			
			if (unsigned char(CarNum[i]) == ch) {
				check = true;
			}
		}
		if (!check) {
			MessageBox::Show("Неверный символ.");
			textBox_car_1letter->Clear();
		}
	}
}
private: System::Void textBox_car_2letter_TextChanged(System::Object^ sender, System::EventArgs^ e) {

	if (Convert::ToString(textBox_car_2letter->Text)->Length > 2) {
		MessageBox::Show("Эта часть номера состоит из 2 букв.");
		textBox_car_2letter->Clear();
	}
	else {
		if (Convert::ToString(textBox_car_2letter->Text)->Length == 2) {
			bool check1 = false;
			bool check2 = false;
			char ch1 = (Convert::ToString(textBox_car_2letter->Text))[0];
			char ch2 = (Convert::ToString(textBox_car_2letter->Text))[1];
			for (int i = 0; CarNum.length() > i; ++i) {

				if (unsigned char(CarNum[i]) == ch1) {
					check1 = true;
				}
				if (unsigned char(CarNum[i]) == ch2) {
					check2 = true;
				}
			}
			if ((!check1)||(!check2)) {
				MessageBox::Show("Встречен неверный символ.");
				textBox_car_2letter->Clear();
			}
		} else
		if (Convert::ToString(textBox_car_2letter->Text)->Length == 1) {
			bool check1 = false;
			char ch1 = (Convert::ToString(textBox_car_2letter->Text))[0];
			for (int i = 0; CarNum.length() > i; ++i) {

				if (unsigned char(CarNum[i]) == ch1) {
					check1 = true;
				}
			}
			if (!check1){
				MessageBox::Show("Встречен неверный символ.");
				textBox_car_2letter->Clear();
			}
		}
	}
}
private: System::Void textBox_car_num_TextChanged(System::Object^ sender, System::EventArgs^ e) {

	if ((textBox_car_num->Text != " ") && (textBox_car_num->Text != "")) {

		if (System::Text::RegularExpressions::Regex::IsMatch(textBox_car_num->Text, "[^0-9]")) {
			MessageBox::Show("В данное поле можно вводить только цифры.");
			textBox_car_num->Clear();
		}else
		if (Convert::ToInt16(textBox_car_num->Text) > 999) {
			MessageBox::Show("Введите трёхзначное число.");
			textBox_car_num->Clear();
		}
	} else {
		textBox_car_num->Clear();
	}
}
private: System::Void textBox_car_color_TextChanged(System::Object^ sender, System::EventArgs^ e) {

	if ((textBox_car_color->Text != " ") && (textBox_car_color->Text != "")) {

		if (!System::Text::RegularExpressions::Regex::IsMatch(textBox_car_color->Text, "^[А-Яа-я\-\\s]+$")) {
			MessageBox::Show("Встречен недопустимый символ.");
			textBox_car_color->Clear();
		}
	}
	else {
		textBox_car_color->Clear();
	}
}
private: System::Void textBox_car_brand_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	if (textBox_car_brand->Text == " ")
		textBox_car_brand->Clear();
}
private: System::Void textBox_car_model_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	if (textBox_car_model->Text == " ")
		textBox_car_model->Clear();
}
private: System::Void button_find_cars_Click(System::Object^ sender, System::EventArgs^ e) {

	if (radioButton_cars_brand->Checked) {
		if (textBox_car_brand->Text != "") {
			msclr::interop::marshal_context context;
			std::vector<int> result = std::vector<int>(0);
			search(context.marshal_as<std::string>(textBox_car_brand->Text), TreeBrand, &result);
			if (result.size() > 0) {
				richTextBox_cars_structure->Clear();
				richTextBox_cars_structure->AppendText("Машины такой марки были обнаружены под номерами: ");
				std::string res = "";
				for (auto i = 0; i < result.size(); ++i) {
					richTextBox_cars_structure->AppendText(gcnew String((result[i]+1).ToString()) + " ");
				}
			}
			else {
				richTextBox_cars_structure->Clear();
				richTextBox_cars_structure->AppendText("Машины такой марки не были обнаружены.");
			}
		}
		else {
			richTextBox_cars_structure->Clear();
			richTextBox_cars_structure->AppendText("Отсутствуют сведения о марке машины.");
		}
	}
	if (radioButton_cars_color->Checked) {
		if (textBox_car_color->Text != "") {
			msclr::interop::marshal_context context;
			std::vector<int> result = std::vector<int>(0);
			search(context.marshal_as<std::string>(textBox_car_color->Text), TreeColor, &result);
			if (result.size() > 0) {
				richTextBox_cars_structure->Clear();
				richTextBox_cars_structure->AppendText("Машины такого цвета были обнаружены под номерами: ");
				std::string res = "";
				for (auto i = 0; i < result.size(); ++i) {
					richTextBox_cars_structure->AppendText(gcnew String((result[i] + 1).ToString()) + " ");
				}
			}
			else {
				richTextBox_cars_structure->Clear();
				richTextBox_cars_structure->AppendText("Машины такого цвета не были обнаружены.");
			}
		}
		else {
			richTextBox_cars_structure->Clear();
			richTextBox_cars_structure->AppendText("Отсутствуют сведения о цвете машины.");
		}
	}
	if (radioButton_cars_model->Checked) {
		if (textBox_car_model->Text != "") {
			msclr::interop::marshal_context context;
			std::vector<int> result = std::vector<int>(0);
			search(context.marshal_as<std::string>(textBox_car_model->Text), TreeModal, &result);
			if (result.size() > 0) {
				richTextBox_cars_structure->Clear();
				richTextBox_cars_structure->AppendText("Машины такой модели были обнаружены под номерами: ");
				std::string res = "";
				for (auto i = 0; i < result.size(); ++i) {
					richTextBox_cars_structure->AppendText(gcnew String((result[i] + 1).ToString()) + " ");
				}
			}
			else {
				richTextBox_cars_structure->Clear();
				richTextBox_cars_structure->AppendText("Не было найдено машин такой модели.");
			}
		}
		else {
			richTextBox_cars_structure->Clear();
			richTextBox_cars_structure->AppendText("Отсутствуют сведения о модели машины.");
		}
	}
	if (radioButton_cars_label->Checked) {
		if ((textBox_car_1letter->Text != "") && (textBox_car_2letter->Text != "") && (textBox_car_num->Text != "")) {
			msclr::interop::marshal_context context;
			std::string label = context.marshal_as<std::string>(textBox_car_1letter->Text + textBox_car_num->Text + textBox_car_2letter->Text);
			int res = Hashtable->Search(list(label, label, label, label, -1));
			if (res != -1) {
				richTextBox_cars_structure->Clear();
				richTextBox_cars_structure->AppendText("Машина с данным госномером находится под номером.");
				richTextBox_cars_structure->AppendText(gcnew String((res+1).ToString()) + " ");
			}
			else {
				richTextBox_cars_structure->Clear();
				richTextBox_cars_structure->AppendText("Автомобиль с таким госномером не был найден.");
			}
		}
		else {
			richTextBox_cars_structure->Clear();
			richTextBox_cars_structure->AppendText("Недостаточно сведений о госномере.");
		}
	}
}
private: System::Void button_add_cars_Click(System::Object^ sender, System::EventArgs^ e) {

	if (
		textBox_car_brand->Text != "" &&
		textBox_car_color->Text != "" &&
		textBox_car_1letter->Text != "" &&
		textBox_car_2letter->Text != "" &&
		textBox_car_model->Text != "" &&
		textBox_car_num->Text != ""
		) {
		msclr::interop::marshal_context context;
		std::string plate = context.marshal_as<std::string>(textBox_car_1letter->Text + textBox_car_num->Text + textBox_car_2letter->Text);
		std::string model = context.marshal_as<std::string>(textBox_car_model->Text);
		std::string brand = context.marshal_as<std::string>(textBox_car_brand->Text);
		std::string color = context.marshal_as<std::string>(textBox_car_color->Text);
		int result = Hashtable->Search(list(plate, brand, model, color, -1));
		if (result != -1) {
			richTextBox_cars_structure->Clear();
			richTextBox_cars_structure->AppendText("Данный автомобиль уже существует.");
		}
		else {
			int num = Record_cars.size();
			Record_cars.push_back(new list(plate, brand, model, color, num));
			Add(brand, num, TreeBrand);
			Add(color, num, TreeColor);
			Add(model, num, TreeModal);
			Hashtable->Add(list(plate, brand, model, color, num));
			richTextBox_cars_data->AppendText(textBox_car_1letter->Text + textBox_car_num->Text + textBox_car_2letter->Text + " " + textBox_car_brand->Text + " " + textBox_car_model->Text + " " + textBox_car_color->Text);
		}
	}
	else {
		MessageBox::Show("Пожалуйста, заполните все данные правильно.");
	}
}
private: System::Void button_delete_cars_Click(System::Object^ sender, System::EventArgs^ e) {

	if (
		textBox_car_brand->Text != "" &&
		textBox_car_color->Text != "" &&
		textBox_car_1letter->Text != "" &&
		textBox_car_2letter->Text != "" &&
		textBox_car_model->Text != "" &&
		textBox_car_num->Text != ""
		) {
		msclr::interop::marshal_context context;
		std::string plate = context.marshal_as<std::string>(textBox_car_1letter->Text + textBox_car_num->Text + textBox_car_2letter->Text);
		std::string model = context.marshal_as<std::string>(textBox_car_model->Text);
		std::string brand = context.marshal_as<std::string>(textBox_car_brand->Text);
		std::string color = context.marshal_as<std::string>(textBox_car_color->Text);
		int result = Hashtable->Search(list(plate, brand, model, color, -1));
		int pos;
		if (result != -1) {
			std::vector<int> results = std::vector<int>(0);
			auto resultss = results;
			TreeCarNum->FindIndex(plate, &results);
			auto answer = MessageBox::Show(this, "Вы действительно хотите удалить автомобиль " + gcnew String(Record_cars[result]->plate.c_str()) + " " + gcnew String(Record_cars[result]->label.c_str()) + " " + gcnew String(Record_cars[result]->model.c_str()) + " " + gcnew String(Record_cars[result]->color.c_str()) + "?", "Удаление авто", MessageBoxButtons::YesNo);
			if (answer == System::Windows::Forms::DialogResult::Yes) {
				System::String^ s = "";
				auto size = results.size();
				if (size != 0) {
					for (auto i = 0; i < size; ++i) {
						s += results.back().ToString() + " ";
						results.pop_back();
					}
				auto answers = MessageBox::Show(this, "Удалите связанные с ним заказы " + s + ".", "Удаление авто", MessageBoxButtons::OK);
				}
			else{
					deleteNode(brand, result, TreeBrand);
					deleteNode(model, result, TreeModal);
					deleteNode(color, result, TreeColor);
					Hashtable->Delete(list(plate, brand, model, color, result));
					richTextBox_cars_data->Clear();
					Record_cars[result] = Record_cars.back();
					Record_cars.pop_back();
					if (result != Record_cars.size()) {
						changeIndex(Record_cars[result]->label, TreeBrand, Record_cars.size(), 0);
						changeIndex(Record_cars[result]->color, TreeColor, Record_cars.size(), 0);
						changeIndex(Record_cars[result]->model, TreeModal, Record_cars.size(), 0);
					}

					auto vec1 = Record_cars;
					auto vec = std::vector<list*>(0);
					for (auto i = Record_cars.size(); i > 0; --i) {
						if (vec1.back()) {
							vec.push_back(vec1.back());
							vec1.pop_back();
						}
					}

					for (auto i = Record_cars.size(); i > 0; --i) {
						if (vec.back())
							richTextBox_cars_data->AppendText(gcnew System::String((vec.back()->plate + " " + vec.back()->label + " " + vec.back()->model + " " + vec.back()->color + "\n").data()));
						vec.pop_back();
					}
				}

			}
		}
			else {
				richTextBox_cars_structure->Clear();
				richTextBox_cars_structure->AppendText("Данного автомобиля не существует.");
			}
		}
		else {
			MessageBox::Show("Пожалуйста, заполните все данные правильно.");
		}
}
private: System::Void textBox8_TextChanged(System::Object^ sender, System::EventArgs^ e) {

	if ((textBox_clients_size_HT->Text != " ") && (textBox_clients_size_HT->Text != "")) {

		if (System::Text::RegularExpressions::Regex::IsMatch(textBox_clients_size_HT->Text, "[^0-9]")) {
			MessageBox::Show("В данное поле можно вводить только цифры.");
			textBox_clients_size_HT->Clear();
		}
		else {
			if (Convert::ToInt16(textBox_clients_size_HT->Text) <= 0) {
				MessageBox::Show("Размер таблицы не может быть не положительным числом.");
				textBox_clients_size_HT->Clear();
			}

			HashTable_size = Convert::ToInt16(textBox_clients_size_HT->Text);

			auto records = Record_clients;
			auto Hashtable2 = new HashTable(HashTable_size);
			int s = 0;
			for (auto i : records) {
				Hashtable2->add(Person(i->getNUM().number, i->getFIO().surname, i->getFIO().name, i->getFIO().f_name, i->getDB().day, i->getDB().month, i->getDB().year, i->getADRESS().address), s);
				s++;
			}
			MHashtable = Hashtable2;
		}
	}
	else {
		textBox_clients_size_HT->Clear();
	}
}
private: System::Void textBox_clients_num_TextChanged(System::Object^ sender, System::EventArgs^ e) {

	if ((textBox_clients_num->Text != " ") && (textBox_clients_num->Text != "")) {

		if (System::Text::RegularExpressions::Regex::IsMatch(textBox_clients_num->Text, "[^0-9]")) {
			MessageBox::Show("В данное поле можно вводить только цифры.");
			textBox_clients_num->Clear();
		}
		else {
			if (Convert::ToDouble(textBox_clients_num->Text) > 1000000000) {
				MessageBox::Show("Слишком большое число");
				textBox_clients_num->Clear();
			}
		}
	}
	else {
		textBox_clients_num->Clear();
	}
}
private: System::Void textBox_clients_address_TextChanged(System::Object^ sender, System::EventArgs^ e) {

	if ((textBox_clients_address->Text != " ") && (textBox_clients_address->Text != "")) {

		if (System::Text::RegularExpressions::Regex::IsMatch(textBox_clients_address->Text, "[^0-9а-яА-Я\-\\s]+")) {
			MessageBox::Show("Неизвестный символ.");
			textBox_clients_address->Clear();
		}
	}
	else {
		textBox_clients_address->Clear();
	}
}
private: System::Void textBox_clients_surname_TextChanged(System::Object^ sender, System::EventArgs^ e) {

	if ((textBox_clients_surname->Text != " ") && (textBox_clients_surname->Text != "")) {

		if (System::Text::RegularExpressions::Regex::IsMatch(textBox_clients_surname->Text, "[^а-яА-Я]+")) {
			MessageBox::Show("Неизвестный символ.");
			textBox_clients_surname->Clear();
		}
	}
	else {
		textBox_clients_surname->Clear();
	}
}
private: System::Void textBox_clients_name_TextChanged(System::Object^ sender, System::EventArgs^ e) {

	if ((textBox_clients_name->Text != " ") && (textBox_clients_name->Text != "")) {

		if (System::Text::RegularExpressions::Regex::IsMatch(textBox_clients_name->Text, "[^а-яА-Я]+")) {
			MessageBox::Show("Неизвестный символ.");
			textBox_clients_name->Clear();
		}
	}
	else {
		textBox_clients_name->Clear();
	}
}
private: System::Void textBox_clients_lastname_TextChanged(System::Object^ sender, System::EventArgs^ e) {

	if ((textBox_clients_lastname->Text != " ") && (textBox_clients_lastname->Text != "")) {

		if (System::Text::RegularExpressions::Regex::IsMatch(textBox_clients_lastname->Text, "[^а-яА-Я]+")) {
			MessageBox::Show("Неизвестный символ.");
			textBox_clients_lastname->Clear();
		}
	}
	else {
		textBox_clients_lastname->Clear();
	}
}
private: System::Void button11_Click(System::Object^ sender, System::EventArgs^ e) {

	richTextBox_clients_structure->Clear();
	String^ str = gcnew String((TreeDB->printSidewaysDB()).data());
	richTextBox_clients_structure->AppendText(str);
}
private: System::Void button_clietns_import_Click(System::Object^ sender, System::EventArgs^ e) {
	if (importD && !importM && (textBox_clients_size_HT->Text != "") && (Convert::ToInt32(textBox_clients_size_HT->Text) > 0)) {

		richTextBox_clients_data->Clear();
		auto reader = System::IO::File::OpenText("Клиенты.txt");
		MHashtable = new HashTable(HashTable_size);
		TreeAdress = new BST<Adress>();
		TreeFIO = new BST<FIO>();
		TreeDB = new BST<DB>();

		importM = true;
		int size = 0;
		while (!reader->EndOfStream) {
			auto str = reader->ReadLine();
			auto _list = str->Split(' ');
			richTextBox_clients_data->AppendText(str);

			Person* el = new Person();
			_list[5] += " " + _list[6];
			if (_list->Length == 8)
				_list[5] += " " + _list[7];
			msclr::interop::marshal_context context;
			el->address = context.marshal_as<std::string>(_list[5]);
			auto date = _list[4];
			el->fio.f_name = context.marshal_as<std::string>(_list[3]);
			el->fio.name = context.marshal_as<std::string>(_list[2]);
			el->fio.surname = context.marshal_as<std::string>(_list[1]);
			el->phone = atoi(context.marshal_as<std::string>(_list[0]).c_str());
			auto date_ = date->Split('.');
			DB db;
			db.day = Int32::Parse(date_[0]);
			db.month = Int32::Parse(date_[1]);
			db.year = Int32::Parse(date_[2]);

			el->date = db;

			TreeAdress->insert(el->address.address, size);
			TreeDB->insert(db, size);
			TreeFIO->insert(FIO(el->fio.surname, el->fio.name, el->fio.f_name), size);
			MHashtable->add(Person(el->phone.number, el->fio.surname, el->fio.name, el->fio.f_name, db.day, db.month, db.year, el->address.address), size);
			Record_clients.push_back(el);

			richTextBox_clients_data->AppendText("\n");
			++size;
		}
		reader->Close();
	}
}
private: System::Void button_clients_export_Click(System::Object^ sender, System::EventArgs^ e) {

	if (MHashtable->tableSize == 0) {
		MessageBox::Show(this, "Вы не импортировали данные. Данное действие сотрёт данные из исходного файла.", "Error", MessageBoxButtons::OK);
	}
	else {
		{
			if (importM) {
				auto vec = std::vector<Person*>(0);
				for (auto i = Record_clients.size(); i > 0; --i) {
					if (Record_clients.back()) {
						vec.push_back(Record_clients.back());
						Record_clients.pop_back();
					}
				}
				System::IO::StreamWriter^ sw = gcnew System::IO::StreamWriter("Клиенты.txt");
				int s = vec.size();
				for (auto i = 0; i < s; ++i) {
					Person* cur = vec.back();
					vec.pop_back();
					std::string coma = " ";
					String^ str = cur->phone.number.ToString() + gcnew String((coma + cur->fio.surname + " " + cur->fio.name + " " + cur->fio.f_name + " ").data()) + cur->date.day.ToString() + "." + cur->date.month.ToString() + "." + cur->date.year.ToString() + " " + gcnew String((cur->address.address).data());
					sw->WriteLine(str);
				}
				sw->Close();
				importM = false;
			}
		}
	}
}
private: System::Void button10_Click(System::Object^ sender, System::EventArgs^ e) {

	richTextBox_clients_structure->Clear();
	String^ str = gcnew String(MHashtable->print().data());
	richTextBox_clients_structure->AppendText(str);
}
private: System::Void button9_Click(System::Object^ sender, System::EventArgs^ e) {

	richTextBox_clients_structure->Clear();
	String^ str = gcnew String(TreeFIO->printSidewaysFIO().data());
	richTextBox_clients_structure->AppendText(str);
}
private: System::Void button8_Click(System::Object^ sender, System::EventArgs^ e) {

	richTextBox_clients_structure->Clear();
	String^ str = gcnew String(TreeAdress->printSidewaysAdress().data());
	richTextBox_clients_structure->AppendText(str);
}
private: System::Void button14_Click(System::Object^ sender, System::EventArgs^ e) {

	if (
		textBox_clients_num->Text != "" &&
		textBox_clients_name->Text != "" &&
		textBox_clients_lastname->Text != "" &&
		textBox_clients_surname->Text != "" &&
		textBox_clients_address->Text != "" &&
		textBox_clients_db->Text != ""
		) {
		msclr::interop::marshal_context context;
		std::string name = context.marshal_as<std::string>(textBox_clients_name->Text);
		std::string surname = context.marshal_as<std::string>(textBox_clients_surname->Text);
		std::string lastname = context.marshal_as<std::string>(textBox_clients_lastname->Text);
		std::string address = context.marshal_as<std::string>(textBox_clients_address->Text);
		std::string str = context.marshal_as<std::string>(textBox_clients_db->Text);
		std::string number = context.marshal_as<std::string>(textBox_clients_num->Text);
		int num = atoi((number).c_str());
		int day = atoi((str.substr(0, 2)).c_str());
		int month = atoi((str.substr(3, 2)).c_str());
		int year = atoi((str.substr(6, 4)).c_str());

		if ((day < 32) && (month < 13) && (year > 1923) && (year <= 2005) && (str != "") && (str[2] == '.') && (str[5] = '.') && (str.length() == 10)) {

			int result = MHashtable->search(Person(num, surname, name, lastname, day, month, year, address));
			int pos;
			if (result != -1) {
				richTextBox_clients_structure->Clear();
				richTextBox_clients_structure->AppendText("Данный клиент уже есть в базе.");
			}
			else {
				int a = Record_clients.size();
			    Record_clients.push_back(new Person(num, surname, name, lastname, day, month, year, address));
				a = Record_clients.size();
				pos = Record_clients.size() - 1;
				TreeAdress->insert(address, pos);
				TreeDB->insert(DB(day, month, year), pos);
				TreeFIO->insert(FIO(surname, name, lastname), pos);
				MHashtable->add(Person(num, surname, name, lastname, day, month, year, address), pos);
				richTextBox_clients_data->AppendText(textBox_clients_num->Text + " " + textBox_clients_name->Text + " " + textBox_clients_surname->Text + " " + textBox_clients_lastname->Text + " " + textBox_clients_db->Text + " " + textBox_clients_address->Text);
			}
		}
		else {
			MessageBox::Show("Неподходящий год рождения.");
			textBox_clients_db->Clear();
		}
	}
	else {
		MessageBox::Show("Пожалуйста, заполните все данные.");
	}
}
private: System::Void button13_Click(System::Object^ sender, System::EventArgs^ e) {

	if (radioButton_clients_DB->Checked) {
		if (richTextBox_clients_data->Text != "") {
			msclr::interop::marshal_context context;
			std::string str = context.marshal_as<std::string>(textBox_clients_db->Text);

			int day = atoi((str.substr(0, 2)).c_str());
			int month = atoi((str.substr(3, 2)).c_str());
			int year = atoi((str.substr(6)).c_str());
			if ((day < 32) && (month < 13) && (year > 1923) && (year <= 2005) && (str != "") && (str[2] == '.') && (str[5] = '.') && (str.length() == 10)) {
				msclr::interop::marshal_context context;
				std::vector<int> result = std::vector<int>(0);
				TreeDB->findNode(TreeDB->GetRoot(), DB(day, month, year), &result);
				if (result.size() > 0) {
					richTextBox_clients_structure->Clear();
					richTextBox_clients_structure->AppendText("Люди, рождённые в этот день были обнаружены: ");
					std::string res = "";
					for (auto i = 0; i < result.size(); ++i) {
						richTextBox_clients_structure->AppendText(gcnew String((result[i] + 1).ToString()) + " ");
					}
				}
				else {
					richTextBox_clients_structure->Clear();
					richTextBox_clients_structure->AppendText("Людей, рождённых в этот день, нет.");
				}
			}
			else {
				richTextBox_clients_structure->Clear();
				richTextBox_clients_structure->AppendText("Некорректная дата рождения.");
			}
		}
		else {
			richTextBox_clients_structure->Clear();
			richTextBox_clients_structure->AppendText("Отсутствуют сведения о дате рождения.");
		}
	}
	if (radioButton_clients_FIO->Checked) {
		if ((textBox_clients_name->Text != "") && (textBox_clients_surname->Text != "") && (textBox_clients_lastname->Text != "")) {
			msclr::interop::marshal_context context;
			std::string name = context.marshal_as<std::string>(textBox_clients_name->Text); 
			std::string surname = context.marshal_as<std::string>(textBox_clients_surname->Text);
			std::string lastname = context.marshal_as<std::string>(textBox_clients_lastname->Text);
			std::vector<int> result = std::vector<int>(0);
			TreeFIO->findNode(TreeFIO->GetRoot(), FIO(surname, name, lastname), &result);
			if (result.size() > 0) {
				richTextBox_clients_structure->Clear();
				richTextBox_clients_structure->AppendText("Люди с этим ФИО: ");
				std::string res = "";
				for (auto i = 0; i < result.size(); ++i) {
					richTextBox_clients_structure->AppendText(gcnew String((result[i] + 1).ToString()) + " ");
				}
			}
			else {
				richTextBox_clients_structure->Clear();
				richTextBox_clients_structure->AppendText("Человека с данным ФИО нет.");
			}
		}
		else {
			richTextBox_clients_structure->Clear();
			richTextBox_clients_structure->AppendText("Отсутствует что-то из следующего: имя, фамилия, отчество.");
		}
	}
	if (radioButton_clients_adress->Checked) {
		if (textBox_clients_address->Text != "") {
			msclr::interop::marshal_context context;
			std::vector<int> result = std::vector<int>(0);
			std::string adres = context.marshal_as<std::string>(textBox_clients_address->Text);
			TreeAdress->findNode(TreeAdress->GetRoot(), Adress(adres), &result);
			if (result.size() > 0) {
				richTextBox_clients_structure->Clear();
				richTextBox_clients_structure->AppendText("Люди, проживающие по этому адресу: ");
				for (auto i = 0; i < result.size(); ++i) {
					richTextBox_clients_structure->AppendText(gcnew String((result[i] + 1).ToString()) + " ");
				}
			}
			else {
				richTextBox_clients_structure->Clear();
				richTextBox_clients_structure->AppendText("Не было найдено людей по этому адресу.");
			}
		}
		else {
			richTextBox_clients_structure->Clear();
			richTextBox_clients_structure->AppendText("Отсутствует адрес.");
		}
	}
	if (radioButton_clients_num->Checked) {
		if (textBox_clients_num->Text != "") {
			msclr::interop::marshal_context context;
			std::string num = context.marshal_as<std::string>(textBox_clients_num->Text);
			int res = MHashtable->search(Person(stoi(num), num, num, num, 0, 0, 0, num));
			if (res != -1) {
				richTextBox_clients_structure->Clear();
				richTextBox_clients_structure->AppendText("Клиент с данным номером телефона находится под номером ");
				richTextBox_clients_structure->AppendText(gcnew String((res + 1).ToString()) + " .");
			}
			else {
				richTextBox_clients_structure->Clear();
				richTextBox_clients_structure->AppendText("Клиент данным номером телефона не был найден.");
			}
		}
		else {
			richTextBox_clients_structure->Clear();
			richTextBox_clients_structure->AppendText("Отсутствует номер телефона.");
		}
	}
}
private: System::Void textBox_clients_db_TextChanged(System::Object^ sender, System::EventArgs^ e) {

	if ((textBox_clients_db->Text != " ") && (textBox_clients_db->Text != "")) {

		if (System::Text::RegularExpressions::Regex::IsMatch(textBox_clients_db->Text, "[^0-9\.]+")) {
			MessageBox::Show("В данное поле можно вводить только цифры.");
			textBox_clients_db->Clear();
		}
	}
	else {
		textBox_clients_db->Clear();
	}
}


private: System::Void button12_Click(System::Object^ sender, System::EventArgs^ e) {

	if (
		textBox_clients_num->Text != "" &&
		textBox_clients_name->Text != "" &&
		textBox_clients_lastname->Text != "" &&
		textBox_clients_surname->Text != "" &&
		textBox_clients_address->Text != "" &&
		textBox_clients_db->Text != ""
		) {
		msclr::interop::marshal_context context;
		std::string name = context.marshal_as<std::string>(textBox_clients_name->Text);
		std::string surname = context.marshal_as<std::string>(textBox_clients_surname->Text);
		std::string lastname = context.marshal_as<std::string>(textBox_clients_lastname->Text);
		std::string address = context.marshal_as<std::string>(textBox_clients_address->Text);
		std::string str = context.marshal_as<std::string>(textBox_clients_db->Text);
		std::string number = context.marshal_as<std::string>(textBox_clients_num->Text);
		int num = atoi((number).c_str());
		int day = atoi((str.substr(0, 2)).c_str());
		int month = atoi((str.substr(3, 2)).c_str());
		int year = atoi((str.substr(6, 4)).c_str());
		int result = MHashtable->search(Person(num, surname, name, lastname, day, month, year, address));
		if (result != -1) {
			msclr::interop::marshal_context context;
			System::String^ space = " ";
			auto results = std::vector<int>(0);
			TreeNum->FindIndex(num, &results);
			auto answer = MessageBox::Show(this, "Вы действительно хотите удалить клиента? " + "+79" + Record_clients[result]->phone.number.ToString() + gcnew String((Record_clients[result]->fio.surname).c_str()) + space + gcnew String((Record_clients[result]->fio.name).c_str()) + space + gcnew String((Record_clients[result]->fio.f_name).c_str()) + space + (Record_clients[result]->date.day).ToString() + "." + (Record_clients[result]->date.month).ToString() + "." + (Record_clients[result]->date.year).ToString() + " " + gcnew String((Record_clients[result]->address.address).c_str()), "Удаление клиента", MessageBoxButtons::YesNo);
			
			if (answer == System::Windows::Forms::DialogResult::Yes) {
				System::String^ s = "";
				auto size = results.size();
				if (size != 0) {
					for (auto i = 0; i < size; ++i) {
						s += results.back().ToString() + " ";
						results.pop_back();
					}
					auto answers = MessageBox::Show(this, "Удалите связанные с ним заказы " + s + ".", "Удаление авто", MessageBoxButtons::OK);
				}
				else {
					TreeAdress->remove(Record_clients[result]->address.address, result);
					TreeDB->remove(DB(Record_clients[result]->date.day, Record_clients[result]->date.month, Record_clients[result]->date.year), result);
					TreeFIO->remove(FIO(Record_clients[result]->fio.surname, Record_clients[result]->fio.name, Record_clients[result]->fio.f_name), result);
					MHashtable->remove(Person(Record_clients[result]->phone.number, Record_clients[result]->fio.surname, Record_clients[result]->fio.name, Record_clients[result]->fio.f_name, Record_clients[result]->date.day, Record_clients[result]->date.month, Record_clients[result]->date.year, Record_clients[result]->address.address));
					richTextBox_clients_data->Clear();
					Record_clients[result]->address.address = Record_clients.back()->address.address;
					Record_clients[result]->date = Record_clients.back()->date;
					Record_clients[result]->fio = Record_clients.back()->fio;
					Record_clients[result]->phone = Record_clients.back()->phone;
					Record_clients.pop_back();
					if (result != Record_clients.size()) {
						TreeAdress->changeIndex(Record_clients[result]->address.address, Record_clients.size(), 0);
						TreeDB->changeIndex(Record_clients[result]->date, Record_clients.size(), 0);
						TreeFIO->changeIndex(Record_clients[result]->fio, Record_clients.size(), 0);
					}

					std::string space = " ";
					auto Space = gcnew String(space.c_str());

					auto vec1 = Record_clients;
					auto vec = std::vector<Person*>(0);
					for (auto i = Record_clients.size(); i > 0; --i) {
						if (vec1.back()) {
							vec.push_back(vec1.back());
							vec1.pop_back();
						}
					}

					for (auto i = Record_clients.size(); i > 0; --i) {
						if (vec.back()) {
							richTextBox_clients_data->AppendText(System::Int32::Parse(vec.back()->phone.number.ToString()) + Space);
							richTextBox_clients_data->AppendText(gcnew String(vec.back()->fio.surname.c_str()) + Space);
							richTextBox_clients_data->AppendText(gcnew String(vec.back()->fio.name.c_str()) + Space);
							richTextBox_clients_data->AppendText(gcnew String(vec.back()->fio.f_name.c_str()) + Space);
							richTextBox_clients_data->AppendText(vec.back()->date.day.ToString() + "." + vec.back()->date.month + "." + vec.back()->date.year + " ");
							richTextBox_clients_data->AppendText(gcnew String(vec.back()->address.address.c_str()) + "\n");
							vec.pop_back();
						}
					}
				}
			}

		}
		else {
			richTextBox_cars_structure->Clear();
			richTextBox_cars_structure->AppendText("Данного человека не существует.");
		}
	}
	else {
		MessageBox::Show("Пожалуйста, заполните все данные правильно.");
	}
}
private: System::Void textBox_orders_pnum_TextChanged(System::Object^ sender, System::EventArgs^ e) {

	if ((textBox_orders_pnum->Text != " ") && (textBox_orders_pnum->Text != "")) {

		if (System::Text::RegularExpressions::Regex::IsMatch(textBox_orders_pnum->Text, "[^0-9]")) {
			MessageBox::Show("В данное поле можно вводить только цифры.");
			textBox_orders_pnum->Clear();
		}
		else {
			if (Convert::ToDouble(textBox_orders_pnum->Text) > 1000000000) {
				MessageBox::Show("Слишком большое число");
				textBox_orders_pnum->Clear();
			}
		}
	}
	else {
		textBox_orders_pnum->Clear();
	}
}
private: System::Void textBox_orders_1letterr_TextChanged(System::Object^ sender, System::EventArgs^ e) {

	if (Convert::ToString(textBox_orders_1letterr->Text)->Length > 1) {
		MessageBox::Show("Эта часть номера состоит из 1 буквы.");
		textBox_orders_1letterr->Clear();
	}
	else  if (Convert::ToString(textBox_orders_1letterr->Text)->Length > 0) {
		bool check = false;
		unsigned char ch = Convert::ToString(textBox_orders_1letterr->Text)[0];
		for (int i = 0; CarNum.length() > i; ++i) {

			if (unsigned char(CarNum[i]) == ch) {
				check = true;
			}
		}
		if (!check) {
			MessageBox::Show("Неверный символ.");
			textBox_orders_1letterr->Clear();
		}
	}
}
private: System::Void textBox_orders_num_TextChanged(System::Object^ sender, System::EventArgs^ e) {

	if ((textBox_orders_num->Text != " ") && (textBox_orders_num->Text != "")) {

		if (System::Text::RegularExpressions::Regex::IsMatch(textBox_orders_num->Text, "[^0-9]")) {
			MessageBox::Show("В данное поле можно вводить только цифры.");
			textBox_orders_num->Clear();
		}
		else
			if (Convert::ToInt16(textBox_orders_num->Text) > 999) {
				MessageBox::Show("Введите трёхзначное число.");
				textBox_orders_num->Clear();
			}
	}
	else {
		textBox_orders_num->Clear();
	}
}
private: System::Void textBox_orders_2letter_TextChanged(System::Object^ sender, System::EventArgs^ e) {

	if (Convert::ToString(textBox_orders_2letter->Text)->Length > 2) {
		MessageBox::Show("Эта часть номера состоит из 2 букв.");
		textBox_orders_2letter->Clear();
	}
	else {
		if (Convert::ToString(textBox_orders_2letter->Text)->Length == 2) {
			bool check1 = false;
			bool check2 = false;
			char ch1 = (Convert::ToString(textBox_orders_2letter->Text))[0];
			char ch2 = (Convert::ToString(textBox_orders_2letter->Text))[1];
			for (int i = 0; CarNum.length() > i; ++i) {

				if (unsigned char(CarNum[i]) == ch1) {
					check1 = true;
				}
				if (unsigned char(CarNum[i]) == ch2) {
					check2 = true;
				}
			}
			if ((!check1) || (!check2)) {
				MessageBox::Show("Встречен неверный символ.");
				textBox_orders_2letter->Clear();
			}
		}
		else
			if (Convert::ToString(textBox_orders_2letter->Text)->Length == 1) {
				bool check1 = false;
				char ch1 = (Convert::ToString(textBox_orders_2letter->Text))[0];
				for (int i = 0; CarNum.length() > i; ++i) {

					if (unsigned char(CarNum[i]) == ch1) {
						check1 = true;
					}
				}
				if (!check1) {
					MessageBox::Show("Встречен неверный символ.");
					textBox_orders_2letter->Clear();
				}
			}
	}
}
private: System::Void textBox_orders_day_TextChanged(System::Object^ sender, System::EventArgs^ e) {

	if ((textBox_orders_day->Text != " ") && (textBox_orders_day->Text != "")) {

		if (System::Text::RegularExpressions::Regex::IsMatch(textBox_orders_day->Text, "[^0-9]")) {
			MessageBox::Show("В данное поле можно вводить только цифры.");
			textBox_orders_day->Clear();
		}
		else {
			if (Convert::ToDouble(textBox_orders_day->Text) > 30) {
				MessageBox::Show("Слишком большое число(не более 30 дней)");
				textBox_orders_day->Clear();
			}
			else
			if (Convert::ToDouble(textBox_orders_day->Text) == 0) {
				MessageBox::Show("Введите число отличное от нуля");
				textBox_orders_day->Clear();
			}
		}
	}
	else {
		textBox_orders_day->Clear();
	}
}
private: System::Void textBox_orders_month_TextChanged(System::Object^ sender, System::EventArgs^ e) {

	if ((textBox_orders_month->Text != " ") && (textBox_orders_month->Text != "")) {

		if (System::Text::RegularExpressions::Regex::IsMatch(textBox_orders_month->Text, "[^0-9]")) {
			MessageBox::Show("В данное поле можно вводить только цифры.");
			textBox_orders_month->Clear();
		}
		else {
			if (Convert::ToDouble(textBox_orders_month->Text) > 12) {
				MessageBox::Show("В году не более 12 месяцев");
				textBox_orders_month->Clear();
			}
			else
			if (Convert::ToDouble(textBox_orders_month->Text) == 0) {
				MessageBox::Show("Введите число отичное от нуля");
				textBox_orders_month->Clear();
			}
		}
	}
	else {
		textBox_orders_month->Clear();
	}
}
private: System::Void textBox_orders_year_TextChanged(System::Object^ sender, System::EventArgs^ e) {

	if ((textBox_orders_year->Text != " ") && (textBox_orders_year->Text != "")) {

		if (System::Text::RegularExpressions::Regex::IsMatch(textBox_orders_year->Text, "[^0-9]")) {
			MessageBox::Show("В данное поле можно вводить только цифры.");
			textBox_orders_year->Clear();
		}
		else {
			if (textBox_orders_year->Text->Length > 4) {
					MessageBox::Show("Недпустимое значение.");
					textBox_orders_year->Clear();
			}
			else
			if (textBox_orders_year->Text->Length == 4) {
				if (Convert::ToDouble(textBox_orders_year->Text) > 2023) {
					MessageBox::Show("Недпустимое значение.");
					textBox_orders_year->Clear();
				}
				else
				if (Convert::ToDouble(textBox_orders_year->Text) < 2020) {
					MessageBox::Show("Недопустимое значение.");
					textBox_orders_year->Clear();
				}
			}
			else
			if (textBox_orders_year->Text->Length == 3) {
				if (Convert::ToDouble(textBox_orders_year->Text) != 202) {
					MessageBox::Show("Недпустимое значение.");
					textBox_orders_year->Clear();
				}
			}
			else
			if (textBox_orders_year->Text->Length == 2) {
				if (Convert::ToDouble(textBox_orders_year->Text) != 20) {
					MessageBox::Show("Недпустимое значение.");
					textBox_orders_year->Clear();
				}
			}
			else
			if (textBox_orders_year->Text->Length == 1) {
				if (Convert::ToDouble(textBox_orders_year->Text) != 2) {
					MessageBox::Show("Недпустимое значение.");
					textBox_orders_year->Clear();
				}
			}
		}
	}
	else {
		textBox_orders_year->Clear();
	}
}
private: System::Void button_orders_import_Click(System::Object^ sender, System::EventArgs^ e) {

	if (!importD) {

		richTextBox_orders_data->Clear();
		auto reader = System::IO::File::OpenText("Заказы.txt");
		DHashtable = new Denis::HashTable();

		importD = true;
		int size = 0;
		
		while (!reader->EndOfStream) {
			auto str = reader->ReadLine();
			auto _list = str->Split(' ');
			richTextBox_orders_data->AppendText(str);

			Denis::Order* el = new Denis::Order();

			msclr::interop::marshal_context context;
			el->_phonnumber = Convert::ToInt32(_list[1]);
			el->_carnumber = context.marshal_as<std::string>(_list[0]);
			el->_date->_day = Convert::ToInt32(_list[2]);
			el->_date->_month = Convert::ToInt32(_list[3]);
			el->_date->_year = Convert::ToInt32(_list[4]);
			el->_time = Convert::ToInt32(_list[5]);

			TreeDate->Insert(Denis::Date(el->_date->_day, el->_date->_month, el->_date->_year), size);
			TreeCarNum->Insert(el->_carnumber, size);
			TreeNum->Insert(el->_phonnumber, size);
			TreeLength->Insert(el->_time, size);
			DHashtable->InsertItem(el->_phonnumber, el->_carnumber, Denis::Date(el->_date->_day, el->_date->_month, el->_date->_year), size);

			Record_orders.push_back(el);

			richTextBox_orders_data->AppendText("\n");
			++size;
		}
		reader->Close();
	}
}
private: System::Void button_orders_export_Click(System::Object^ sender, System::EventArgs^ e) {

	if (DHashtable->_count == 0) {
		MessageBox::Show(this, "Вы не импортировали данные. Данное действие сотрёт данные из исходного файла.", "Error", MessageBoxButtons::OK);
	}
	else {
		{
			if (importD) {
				auto vec = std::vector<Denis::Order*>(0);
				for (auto i = Record_orders.size(); i > 0; --i) {
					if (Record_orders.back()) {
						vec.push_back(Record_orders.back());
						Record_orders.pop_back();
					}
				}
				System::IO::StreamWriter^ sw = gcnew System::IO::StreamWriter("Заказы.txt");
				int s = vec.size();
				for (auto i = 0; i < s; ++i) {
					Denis::Order* cur = vec.back();
					vec.pop_back();
					String^ str = cur->_phonnumber.ToString() + " " + gcnew String((cur->_carnumber).data()) + " " + cur->_date->_day.ToString() + " " + cur->_date->_month.ToString() + " " + cur->_date->_year.ToString() + " " + cur->_time.ToString();
					sw->WriteLine(str);
				}
				sw->Close();
				importD = false;
			}
		}
	}
}
private: System::Void button_orders_delete_Click(System::Object^ sender, System::EventArgs^ e) {

	if (
		textBox_orders_1letterr->Text != "" &&
		textBox_orders_2letter->Text != "" &&
		textBox_orders_num->Text != "" &&
		textBox_orders_day->Text != "" &&
		textBox_orders_month->Text != "" &&
		textBox_orders_year->Text != "" &&
		textBox_orders_pnum->Text != "" &&
		comboBox_orders_length->Text != ""
		) {

		msclr::interop::marshal_context context;
		int phonnumber = Convert::ToInt32(textBox_orders_pnum->Text);
		std::string carnumber = context.marshal_as<std::string>(textBox_orders_1letterr->Text + textBox_orders_num->Text + textBox_orders_2letter->Text);
		int day = Convert::ToInt32(textBox_orders_day->Text);
		int month = Convert::ToInt32(textBox_orders_month->Text);
		int year = Convert::ToInt32(textBox_orders_year->Text);
		int time = Convert::ToInt32(comboBox_orders_length->Text);
		int result = DHashtable->Search(Denis::Date(day, month, year), phonnumber, carnumber);
		if (result != -1) {
			auto answer = MessageBox::Show(this, "Вы действительно хотите удалить заказ " + Record_orders[result]->_phonnumber.ToString() + " " + gcnew String(Record_orders[result]->_carnumber.c_str()) + " " + Record_orders[result]->_date->_day.ToString() + " " + Record_orders[result]->_date->_month.ToString() + " " + Record_orders[result]->_date->_year.ToString() + " " + Record_orders[result]->_time.ToString() + "?", "Удаление заказа", MessageBoxButtons::YesNo);
			if (answer == System::Windows::Forms::DialogResult::Yes) {

				TreeCarNum->Delete(carnumber, result);
				TreeDate->Delete(Denis::Date(day, month, year), result);
				TreeLength->Delete(time, result);
				TreeNum->Delete(phonnumber, result);
				DHashtable->DeleteItem(Denis::Date(day, month, year), phonnumber, carnumber);

				richTextBox_orders_data->Clear();
				Record_orders[result] = Record_orders.back();
				Record_orders.pop_back();
				if (result != Record_orders.size()) {
					TreeCarNum->ChangeIndex(Record_orders[result]->_carnumber, Record_orders.size(), result);
					TreeDate->ChangeIndex(Denis::Date(Record_orders[result]->_date->_day, Record_orders[result]->_date->_month, Record_orders[result]->_date->_year), Record_orders.size(), result);
					TreeLength->ChangeIndex(Record_orders[result]->_time, Record_orders.size(), result);
					TreeNum->ChangeIndex(Record_orders[result]->_phonnumber, Record_orders.size(), result);
				}

				auto vec1 = Record_orders;
				auto vec = std::vector<Denis::Order*>(0);
				for (auto i = Record_orders.size(); i > 0; --i) {
					if (vec1.back()) {
						vec.push_back(vec1.back());
						vec1.pop_back();
					}
				}

				for (auto i = Record_orders.size(); i > 0; --i) {
					if (vec.back())
						richTextBox_orders_data->AppendText(vec.back()->_phonnumber.ToString() + " " + gcnew String(vec.back()->_carnumber.c_str()) + " " + vec.back()->_date->_day.ToString() + " " + vec.back()->_date->_month.ToString() + " " + vec.back()->_date->_year.ToString() + " " + vec.back()->_time.ToString() + "\n");
					vec.pop_back();
				}
			}
			if (answer == System::Windows::Forms::DialogResult::No);

		}
		else {
			richTextBox_orders_structure->Clear();
			richTextBox_orders_structure->AppendText("Данного заказа не существует.");
		}
	}
	else {
		MessageBox::Show("Пожалуйст,а заполните все данные правильно.");
	}
}
private: System::Void button_orders_HT_Click(System::Object^ sender, System::EventArgs^ e) {

	richTextBox_orders_structure->Clear();
	String^ str = gcnew String(DHashtable->PrintHashTable().data());
	richTextBox_orders_structure->AppendText(str);
}
private: System::Void button_orders_number_Click(System::Object^ sender, System::EventArgs^ e) {

	richTextBox_orders_structure->Clear();
	String^ str = gcnew String(TreeCarNum->PrintOnSideS(6).data());
	richTextBox_orders_structure->AppendText(str);
}
private: System::Void button_orders_pnumber_Click(System::Object^ sender, System::EventArgs^ e) {

	richTextBox_orders_structure->Clear();
	String^ str = gcnew String(TreeNum->PrintOnSideInt(6).data());
	richTextBox_orders_structure->AppendText(str);
}
private: System::Void button_orders_date_Click(System::Object^ sender, System::EventArgs^ e) {

	richTextBox_orders_structure->Clear();
	String^ str = gcnew String(TreeDate->PrintOnSide(6).data());
	richTextBox_orders_structure->AppendText(str);
}
private: System::Void button_orders_length_Click(System::Object^ sender, System::EventArgs^ e) {

	richTextBox_orders_structure->Clear();
	String^ str = gcnew String(TreeLength->PrintOnSideInt(6).data());
	richTextBox_orders_structure->AppendText(str);
}
private: System::Void button_orders_find_Click(System::Object^ sender, System::EventArgs^ e) {

	if (radioButton_orders_number->Checked) {
		if ((textBox_orders_num->Text != "") &&
			(textBox_orders_1letterr->Text != "") &&
			(textBox_orders_2letter->Text != "")
			) {
			msclr::interop::marshal_context context;
			std::vector<int> result = std::vector<int>(0);
			TreeCarNum->FindIndex(context.marshal_as<std::string>(textBox_orders_1letterr->Text + textBox_orders_num->Text + textBox_orders_2letter->Text), &result);
			if (result.size() > 0) {
				richTextBox_orders_structure->Clear();
				richTextBox_orders_structure->AppendText("Заказы с данным автомобилем: ");
				System::String^ res = " " ;
				for (auto i = 0; i < result.size(); ++i) {
					richTextBox_orders_structure->AppendText(gcnew String((result[i] + 1).ToString()) + res);
				}
			}
			else {
				richTextBox_orders_structure->Clear();
				richTextBox_orders_structure->AppendText("Заказы с данным автомобилем не были обнаружены.");
			}
		}
		else {
			richTextBox_orders_structure->Clear();
			richTextBox_orders_structure->AppendText("Отсутствует госномер.");
		}
	}
	if (radioButton_orders_pnumber->Checked) {
		if (textBox_orders_pnum->Text != "") {
			msclr::interop::marshal_context context;
			std::vector<int> result = std::vector<int>(0);
			TreeNum->FindIndex(Convert::ToInt32(textBox_orders_pnum->Text), &result);
			if (result.size() > 0) {
				richTextBox_orders_structure->Clear();
				richTextBox_orders_structure->AppendText("Заказы, оформленные на данный номер телефона: ");
				std::string res = "";
				for (auto i = 0; i < result.size(); ++i) {
					richTextBox_orders_structure->AppendText(gcnew String((result[i] + 1).ToString()) + " ");
				}
			}
			else {
				richTextBox_orders_structure->Clear();
				richTextBox_orders_structure->AppendText("Нет заказов, оформленных на данный номер телефона.");
			}
		}
		else {
			richTextBox_orders_structure->Clear();
			richTextBox_orders_structure->AppendText("Отсутствует номер телефона.");
		}
	}
	if (radioButton_orders_date->Checked) {
		if ((textBox_orders_day->Text != "") &&
			(textBox_orders_month->Text != "") &&
			(textBox_orders_year->Text != "")
		){
			msclr::interop::marshal_context context;
			std::vector<int> result = std::vector<int>(0);
			TreeDate->FindIndex(Denis::Date(Convert::ToInt32(textBox_orders_day->Text), Convert::ToInt32(textBox_orders_month->Text), Convert::ToInt32(textBox_orders_year->Text)), &result);
			if (result.size() > 0) {
				richTextBox_orders_structure->Clear();
				richTextBox_orders_structure->AppendText("Заказы, совершенные в данные день: ");
				std::string res = "";
				for (auto i = 0; i < result.size(); ++i) {
					richTextBox_orders_structure->AppendText(gcnew String((result[i] + 1).ToString()) + " ");
				}
			}
			else {
				richTextBox_orders_structure->Clear();
				richTextBox_orders_structure->AppendText("Заказов в данный день не было.");
			}
		}
		else {
			richTextBox_orders_structure->Clear();
			richTextBox_orders_structure->AppendText("Отсутствуют данные о дне.");
		}
	}
	if (radioButton_orders_length->Checked) {
		if (comboBox_orders_length->Text != "") {
			msclr::interop::marshal_context context;
			std::vector<int> result = std::vector<int>(0);
			TreeLength->FindIndex(Convert::ToInt32(comboBox_orders_length->Text), &result);
			if (result.size() > 0) {
				richTextBox_orders_structure->Clear();
				richTextBox_orders_structure->AppendText("Заказы заданной длительности: ");
				std::string res = "";
				for (auto i = 0; i < result.size(); ++i) {
					richTextBox_orders_structure->AppendText(gcnew String((result[i] + 1).ToString()) + " ");
				}
			}
			else {
				richTextBox_orders_structure->Clear();
				richTextBox_orders_structure->AppendText("Заказы данной длительности не были найдены.");
			}
		}
		else {
			richTextBox_orders_structure->Clear();
			richTextBox_orders_structure->AppendText("Отсутствует длительность заказа.");
		}
	}
	if (radioButton_orders_comb->Checked) {
		if ((textBox_orders_1letterr->Text != "") && 
			(textBox_orders_2letter->Text != "") && 
			(textBox_orders_num->Text != "") &&
			(textBox_orders_pnum->Text != "") &&
			(textBox_orders_day->Text != "") &&
			(textBox_orders_month->Text != "") &&
			(textBox_orders_year->Text != "")
			) {
			msclr::interop::marshal_context context;
			int phonnumber = Convert::ToInt32(textBox_orders_pnum->Text);
			std::string carnumber = context.marshal_as<std::string>(textBox_orders_1letterr->Text + textBox_orders_num->Text + textBox_orders_2letter->Text);
			int day = Convert::ToInt32(textBox_orders_day->Text);
			int month = Convert::ToInt32(textBox_orders_month->Text);
			int year = Convert::ToInt32(textBox_orders_year->Text);
			int time = Convert::ToInt32(comboBox_orders_length->Text);
			int res = DHashtable->Search(Denis::Date(day, month, year), phonnumber, carnumber);
			if (res != -1) {
				richTextBox_orders_structure->Clear();
				richTextBox_orders_structure->AppendText("Заказы данного автомобиля в данный день и конкретным человеков: ");
				richTextBox_orders_structure->AppendText(gcnew String((res + 1).ToString()) + " ");
			}
			else {
				richTextBox_orders_structure->Clear();
				richTextBox_orders_structure->AppendText("Заказ, подходящий данным критериям, не был найден.");
			}
		}
		else {
			richTextBox_orders_structure->Clear();
			richTextBox_orders_structure->AppendText("Недостаточно сведений об интересующих заказах.");
		}
	}
}
private: System::Void button_orders_add_Click(System::Object^ sender, System::EventArgs^ e) {


	if (
		textBox_orders_num->Text != "" &&
		textBox_orders_1letterr->Text != "" &&
		textBox_orders_2letter->Text != "" &&
		textBox_orders_pnum->Text != "" &&
		textBox_orders_day->Text != "" &&
		textBox_orders_year->Text != "" &&
		textBox_orders_month->Text != "" &&
		comboBox_orders_length->Text != ""
		) {
		msclr::interop::marshal_context context;
		int phonnumber = Convert::ToInt32(textBox_orders_pnum->Text);
		std::string carnumber = context.marshal_as<std::string>(textBox_orders_1letterr->Text + textBox_orders_num->Text + textBox_orders_2letter->Text);
		int day = Convert::ToInt32(textBox_orders_day->Text);
		int month = Convert::ToInt32(textBox_orders_month->Text);
		int year = Convert::ToInt32(textBox_orders_year->Text);
		int time = Convert::ToInt32(comboBox_orders_length->Text);
		int result = DHashtable->Search(Denis::Date(day, month, year), phonnumber, carnumber);
		if (result != -1) {
			richTextBox_orders_structure->Clear();
			richTextBox_orders_structure->AppendText("Данный заказ уже существует.");
		}
		else {
			std::string s = "1";
			int res1 = Hashtable->Search(list(carnumber, s, s, s, 1));
			int res2 = MHashtable->search(Person(phonnumber, s, s, s, 1, 1, 1, s));
			if ((res1 != -1) && (res2 != -1)) {
				richTextBox_orders_data->AppendText(textBox_orders_pnum->Text + " " + textBox_orders_1letterr->Text + textBox_orders_num->Text + textBox_orders_2letter->Text + " " + textBox_orders_day->Text + " " + textBox_orders_month->Text + " " + textBox_orders_year->Text + " " + comboBox_orders_length->Text);
				Record_orders.push_back(new Denis::Order(phonnumber, carnumber, day, month, year, time));
				int num = Record_orders.size();
				TreeCarNum->Insert(carnumber, num-1);
				TreeNum->Insert(phonnumber, num-1);
				TreeDate->Insert(Denis::Date(day, month, year), num-1);
				TreeLength->Insert(time, num-1);
				DHashtable->InsertItem(phonnumber, carnumber, Denis::Date(day, month, year), num-1);
			}
			else{
				richTextBox_orders_structure->Clear();
				richTextBox_orders_structure->AppendText("Проверьте другие справочники. Данного человека и/или автомобиля не существует.");
			}
		}
	}
	else {
		MessageBox::Show("Пожалуйста заполните все данные правильно.");
	}
}
};
}