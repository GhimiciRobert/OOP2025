#include<string>
#include<vector>
#include<map>
#include<iostream>
#include<algorithm>
using namespace std;

class materie {
protected:
	string tip;
	int credite;
	string nume;
public:
	materie(string tip, string nume, int credite) : tip(tip), nume(nume), credite(credite) {};
	~materie() {};
	string getNume() const { return nume; }
	string getTip() const { return tip; }
	int getCredite() const { return credite; }

	virtual void afisare() = 0;
};

class matematica :public materie {
public:
	matematica() : materie("obligatoriu", "matematica", 5) {};
	~matematica() {};
	void afisare() override {
		cout << "matematica - " << tip << " - " << credite << " credite\n";
	}
};

class romana :public materie {
public:
	romana() : materie("obligatoriu", "roamana", 5) {};
	~romana() {};
	void afisare() override {
		cout << "roamana - " << tip << " - " << credite << " credite\n";
	}
};

class engleza :public materie {
public:
	engleza() : materie("facultativ", "engleza", 5) {};
	~engleza() {};
	void afisare() override {
		cout << "engleza - " << tip << " - " << credite << " credite\n";
	}
};

class informatica :public materie {
public:
	informatica() : materie("obligatoriu", "informatica", 5) {};
	~informatica() {};
	void afisare() override {
		cout << "informatica - " << tip << " - " << credite << " credite\n";
	}
};

class optional1 :public materie {
public:
	optional1() : materie("optional", "optional1", 5) {};
	~optional1() {};
	void afisare() override {
		cout << "optional1 - " << tip << " - " << credite << " credite\n";
	}
};

class student {
private:
	string nume;
	string nr_matricol;
	string program_invatare;
	map<materie*, double> note_materii;
public:
	student(string n, string nr_m, string p) : nume(n), nr_matricol(nr_m), program_invatare(p) {};
	void adauga_nota(materie* materie, float nota) {
		note_materii[materie] = nota;
	}
	double calc_medie() {
		double s = 0;
		for (auto it=note_materii.begin();it!=note_materii.end();it++)
		{
			s += it->second;
		}
		return s / note_materii.size();
	}
	void sterge_materii() {
		for (auto& p : note_materii)
		{
			delete p.first;
		}
		note_materii.clear();
	}
	string get_nume() {
		return nume;
	}
	string get_nrmat() {
		return nr_matricol;
	}
	string prog_invatare(){
		return program_invatare;
	}
	double get_nota(const string& materie_cautata) {
		for (auto& p : note_materii)
		{
			if (p.first->getNume() == materie_cautata)
				return p.second;
		}
		return -1;
	}

};

class catalog {
protected:
	vector<student*> studenti;
public:
	virtual ~catalog() {
		for (auto& p : studenti) {
			p->sterge_materii();
			delete p;
		}	
	}
	virtual void adauga_student(student* std) = 0;
	virtual void afis_ranking() = 0;
};

class catalog_ro : public catalog {
public:
	void adauga_student(student* std) override {
		if (std->prog_invatare() == "romana")
			studenti.push_back(std);
	}
	void afis_ranking() override {
		vector<student*> ordonati;
		ordonati = studenti;
		sort(ordonati.begin(), ordonati.end(), [](student* a, student* b) {
			return a->calc_medie() > b->calc_medie();
			});
		for (auto& p : ordonati)
			printf("%s a obtinut media %f\n", p->get_nume().c_str(), p->calc_medie());
	}
};

class catalog_eng : public catalog {
public:
	void adauga_student(student* std) override {
		if (std->prog_invatare() == "engleza")
			studenti.push_back(std);
	}
	void afis_ranking() override {
		vector<student*> ordonati;
		ordonati = studenti;
		sort(ordonati.begin(), ordonati.end(), [](student* a, student* b) {
			return a->calc_medie() > b->calc_medie();
			});
		for (auto& p : ordonati)
			printf("%s a obtinut media %2f\n", p->get_nume().c_str(), p->calc_medie());
	}
};


int main()
{
	catalog_ro cat_ro;
	student* s1 = new student("Saraiman Antonia", "583048937", "romana");
	s1->adauga_nota(new matematica, 5.0f);
	s1->adauga_nota(new romana, 4.0f);

	student* s2 = new student("Ghimici Andrei-Robert", "756732067", "romana");
	s2->adauga_nota(new matematica, 10.0f);
	s2->adauga_nota(new romana, 10.0f);

	cat_ro.adauga_student(s1);
	cat_ro.adauga_student(s2);

	cat_ro.afis_ranking();
}