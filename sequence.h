#pragma once
#include <iostream>
#include <memory>
#include <vector>
namespace sequence {
    class Progression;
    using ProgressionPtr = std::shared_ptr<Progression>;

    class Progression {
    public:
        virtual int get_num() const = 0;

        virtual double get_n_elem(int n) = 0;

        virtual double get_sum(int n) = 0;

        virtual double get_a() const = 0;

        virtual double get_first_mem() const = 0;

        virtual bool equals(ProgressionPtr other) const = 0;

        virtual ~Progression() = default;

    protected:
        Progression() = default;
        Progression(const Progression&) = default;
        Progression& operator=(const Progression&) = default;
    };

    class ArifProgression : public Progression {
    private:
        double _first_member;
        double _a;
        int _num;
    public:
        int get_num() const override;

        ArifProgression(double a, double first_mem, int num);

        double get_n_elem(int n) override;

        double get_sum(int n) override;

        double get_a() const override;

        double get_first_mem() const override;

        bool equals(ProgressionPtr other) const override;
    };

    class GeomProgression : public Progression {
    private:
        double _first_member;
        double _a;
        int _num;
    public:
        int get_num() const override;

        GeomProgression(double a, double first_mem, int num);

        double get_n_elem(int n) override;

        double get_sum(int n) override;

        double get_a() const  override;

        double get_first_mem() const override;

        bool equals(ProgressionPtr other) const override;
    };



	class Sequence {
    private:
        int _index;
        std::vector<ProgressionPtr> _progs;
	public:
        

		Sequence();
        int get_index();
        void set_index(int i);
        double get_n_elem(int n);
        double get_sum(int n);
        ProgressionPtr get_prog_with_max_sum(int n);
        void add_progression(ProgressionPtr pr);
        ProgressionPtr operator[](int index) const;
        void remove(int index);
        void overwrite(int index, ProgressionPtr prog);
	};

    bool operator==(Sequence lhs, Sequence rhs);
    bool operator!=(Sequence lhs, Sequence rhs);
    std::ostream& operator<< (std::ostream& out, Sequence& s);
    std::ostream& operator<< (std::ostream& out, Progression* s);

    class SequenceList {
    private:
        Sequence** _sequences;
        int _size;
    public:
        SequenceList();
        SequenceList( SequenceList& other);
        ~SequenceList();
        int get_size();
        Sequence get_seq(const int index) const;
        void add(Sequence* sec);
        void insert(int index, Sequence* f);
        void remove(int index);
        Sequence* operator[](int index) const;
        SequenceList& operator=(SequenceList rhs);
        void swap(SequenceList& other);
    };
    
}
