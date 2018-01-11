#include "config.hpp"

nclude<string>
#include<vector>
#include<iostream>
#include<dirent.h>
#include<sys/stat.h>

using namespace std;

vector<string> getAllFiles(string directory, vector<string>& target){
        vector<string> files;
        struct dirent* d_ent = NULL;
        DIR* dir = opendir(directory.c_str());
        if(dir == NULL){
                cout << "The directory " << directory << " does not exist!" << endl;
                return files;
        }
        if(directory[directory.length()-1] == '/')
                directory = directory.substr(0, directory.length() - 1);
        while((d_ent = readdir(dir)) != NULL){
                string childname(d_ent->d_name);
                if((childname != ".") && (childname != "..")){
                        string child = directory + string("/") + childname;
                        if(d_ent->d_type == DT_DIR ){
                                vector<string> ans = getAllFiles(child, target);
                                files.insert(files.end(), ans.begin(), ans.end());
                        }
                        else if(target.size() > 0){
                                for(int i = 0; i < target.size(); i++){
                                        if(child.rfind(target[i]) != string::npos){
                                                files.push_back(child);
                                                break;
                                        }
                                }
                        }
                        else{
                                files.push_back(child);
                        }
                }
        }
        closedir(dir);
        return files;
}

vector<string> getAllImgFiles(string directory){
        string s[] = {".jpg", ".jpeg", ".png"};
        vector<string> pic_target (s, s + sizeof(s) / sizeof(string));
        return getAllFiles(directory, pic_target);
}

vector<string> getAllLabFiles(string directory){
        string s[] = {".label"};
        vector<string> lab_target (s, s + sizeof(s) / sizeof(string));
        return getAllFiles(directory, lab_target);
}


