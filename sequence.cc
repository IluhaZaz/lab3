#include <sequences/sequence.h>
#include <cmath>
#include <stdexcept>
#include <cstdio>
#include <memory>
#include <vector>
using namespace std;
using namespace sequence;

using ProgressionPtr = std::shared_ptr<Progression>;


GeomProgression::GeomProgression(double a, double first_mem, int num) {
	if (a == 0) {
		throw invalid_argument("[Progression:Progression] Denominator mustn't be zero.");
	}
	if (first_mem == 0) {
		throw invalid_argument("[Progression:Progression] First member mustn't be zero.");
	}
	else {
		_a = a;
		_first_member = first_mem;
		_num = num;
	}
}

ArifProgression::ArifProgression(double a, double first_mem, int num){
	_a = a;
	_first_member = first_mem;
	_num = num;
}


double ArifProgression::get_n_elem(int n) {
	if (n <= 0) {
		throw invalid_argument("[Progression::get_n_elem] Negative number of progression member.");
	}
	return _first_member + _a * (n - 1);
}

double GeomProgression::get_n_elem(int n) {
	if (n <= 0) {
		throw invalid_argument("[Progression::get_n_elem] Negative number of progression member.");
	}
	return _first_member * pow(_a, n - 1);
}


int sequence::ArifProgression::get_num() const
{
	return _num;
}

int sequence::GeomProgression::get_num() const
{
	return _num;
}


bool GeomProgression::equals(ProgressionPtr other) const {
	const auto downcasted_other = dynamic_pointer_cast<GeomProgression>(other);
	if (downcasted_other == nullptr) {
		return false;
	}
	return (this->get_a() == downcasted_other->get_a()) && (this->get_num() == downcasted_other->get_num()) && (this->get_first_mem() == downcasted_other->get_first_mem());
}

bool ArifProgression::equals(ProgressionPtr other) const {
	const auto downcasted_other = dynamic_pointer_cast<ArifProgression>(other);
	if (downcasted_other == nullptr) {
		return false;
	}
	return (this->get_a() == downcasted_other->get_a()) && (this->get_num() == downcasted_other->get_num()) && (this->get_first_mem() == downcasted_other->get_first_mem());
}

void Sequence::add_progression(ProgressionPtr pr) {
	_progs.push_back(pr);
	_index++;
}

ProgressionPtr sequence::Sequence::operator[](int index) const
{
	if (index < 0 || _index <= index) {
		throw out_of_range("[Sequence::operator[]] Index is out of range.");
	}
	return _progs.at(index);
}

void sequence::Sequence::remove(int index)
{
	_progs.erase(_progs.begin() + index);
	_index--;
}


double Sequence::get_n_elem(int n) {
	if(n <= 0)
		throw invalid_argument("[Sequence::get_n_elem] Negative number of progression member.");
	if(_index == 0)
		throw runtime_error("[Sequence::get_n_elem] Empty sequence.");
	for (int i = 0; i < _index; i++) {
		n -= _progs[i]->get_num();
		if (n<=0) {
			return _progs[i]->get_n_elem(abs(n) + 1);
		}
	}
	return _progs[_index - 1]->get_n_elem(n + _progs[_index - 1]->get_num());
}

double Sequence::get_sum(int n)
{
	if (n <= 0)
		throw invalid_argument("[Sequence::get_sum] Negative number of progression member.");
	if (_index == 0)
		throw runtime_error("[Sequence::get_sum] Empty sequence.");
	double sum = 0;
	for (int i = 0; i < _index; i++) {
		for(int j = 1; j <= _progs[i]->get_num(); j++){
			sum += _progs[i]->get_n_elem(j);
			n--;
			if (n == 0)
				return sum;
		}
	}
}

double ArifProgression::get_sum(int n) {
	if (n <= 0)
		throw invalid_argument("[Progression::get_sum] Negative index.");
	return (2 * _first_member + _a * (n - 1)) / 2 * n;
}

double GeomProgression::get_sum(int n) {
	if (n <= 0)
		throw invalid_argument("[Progression::get_sum] Negative index.");
	if (_a != 1)
		return (_first_member * (1 - pow(_a, n))) / (1 - _a);
	else
		return _first_member * n;
}



ProgressionPtr Sequence::get_prog_with_max_sum(int n){
	ProgressionPtr pr = make_shared <Progression>();
	pr = _progs[0];
	if (n <= 0)
		throw invalid_argument("[Sequence::get_max_sum] Negative number.");
	double max = _progs[0]->get_sum(n);
	for (int i = 1; i < _index; i++) {
		if (_progs[i]->get_sum(n) >= max)
		{
			max = _progs[i]->get_sum(n);
			pr = _progs[i];
		}
	}
	return pr;
}


double ArifProgression::get_a() const {
	return _a;
}

double GeomProgression::get_a() const {
	return _a;
}

double ArifProgression::get_first_mem() const {
	return _first_member;
}

double GeomProgression::get_first_mem() const {
	return _first_member;
}





void sequence::Sequence::set_index(int i)
{
	_index = i;
}

int Sequence::get_index()
{
	return _index;
}

bool sequence::operator==(Sequence lhs, Sequence rhs)
{
	if (lhs.get_index() != rhs.get_index())
		return false;
	for (int i = 0; i < lhs.get_index(); i++) {
		if (lhs[i] != rhs[i])
			return false;
	}
	return true;
}

bool sequence::operator!=(Sequence lhs, Sequence rhs)
{
	return !(lhs == rhs);
}

std::ostream& sequence::operator<< (std::ostream& out, Sequence& sec)
{
	bool flag = 1;
	for (int i = 0; i < sec.get_index(); i++)
	{
		for (int j = 1; j <= sec[i]->get_num(); j++) {
			if (flag == 1)
				std::cout << sec[i]->get_n_elem(j);
			else
				std::cout << ", " << sec[i]->get_n_elem(j);
			flag = 0;
		}
		std::cout << "   ";
	}
	return out;
}

std::ostream& sequence:: operator<<(std::ostream& out, Progression* s) {
	for (int i = 1; i <= s->get_num(); i++) {
		std::cout << s->get_n_elem(i) << " ";
	}
	return out;
}

void sequence::Sequence::overwrite(int index, ProgressionPtr prog)
{
	_progs.emplace(_progs.begin() + index, prog);
}

