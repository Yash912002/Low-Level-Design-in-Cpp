#include <bits/stdc++.h>
using namespace std;

class WalkableRobot {
public:
  virtual void walk() const = 0;
  virtual ~WalkableRobot() = default;
};

class NormalWalk : public WalkableRobot {
public:
  void walk() const override { cout << "Normal walk" << endl; }
};

class NoWalk : public WalkableRobot {
public:
  void walk() const override { cout << "Robot can't walk" << endl; }
};

class TalkableRobot {
public:
  virtual void talk() const = 0;
  virtual ~TalkableRobot() = default;
};

class NormalTalk : public TalkableRobot {
public:
  void talk() const override { cout << "Normal Talk" << endl; }
};

class NoTalk : public TalkableRobot {
public:
  void talk() const override { cout << "Robot can't Talk" << endl; }
};

class Robot {
private:
  WalkableRobot *walkBehavior;
  TalkableRobot *talkBehavior;

public:
  Robot(WalkableRobot *w, TalkableRobot *t) {
    this->walkBehavior = w;
    this->talkBehavior = t;
  }

  void walk() { walkBehavior->walk(); }
  void talk() { talkBehavior->talk(); }

  virtual void Projection() const = 0;

  virtual ~Robot() {
    cout << "Robot destructor called. " << endl;
    delete walkBehavior;
    delete talkBehavior;
  }
};

class WorkerRobot : public Robot {
public:
  WorkerRobot(WalkableRobot *w, TalkableRobot *t) : Robot(w, t) {}

  void Projection() const override { cout << "Worker Robot called" << endl; }
};

int main() {
  Robot *r1 = new WorkerRobot(new NormalWalk(), new NormalTalk());
  r1->walk();
  r1->talk();
  delete r1;

  Robot *r2 = new WorkerRobot(new NoWalk(), new NoTalk());
  r2->walk();
  r2->talk();

  delete r2;
  return 0;
}