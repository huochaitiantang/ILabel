
typedef enum x{
	CLS,
	BOX,
	SEG
} label_type_e;

class Label{
	public:
		void init_from_file(string lab_name);
		void init_from_new(label_type_e lte);
		void save_to_file(string img_name);
		int get_type();
		int get_cls_val();
		vector<vector<float> > get_box_val();
		set_cls_val(int cls);
		set_box_val(vector<vector<float> > boxes);
		
	protected:
		label_type_e type; // cls, box, seg
		int cls_val; // class
		vector<vector<float>> box_val; //x1, y1, x2, y2, class
};

class Config{
	public:
		void init_from_file(string cfg_name);
		void init_from_new(label_type_e lte, string imgdir, string labdir, vector<string>& clsmap);
		void save_to_file();
		vector<string> get_cls_map();
		void set_cls_map(vector<string> clsmap);
		string get_cur_img_name();
		Label get_cur_label();
		void edit_cur_label();
		void next_img();
	protected:
		string cfg_name;
		string img_dir;
		string lab_dir;
		label_type_e label_type;
		int cur_img_ind;
		string cur_img_name;
		Label cur_label;
		bool cur_img_labeled;
		vector<string> cls_map;
		vector<string> all_img_names;
		vector<bool> all_img_labeled;
		int labeled_cnt;
		int all_cnt;
		float labeled_ratio;
};
