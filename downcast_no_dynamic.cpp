
class bar;
class mumble;
class submumble;

class foo
{
public:

  virtual bar *downcast_to_bar()
  {  return nullptr;  }

  virtual mumble *downcast_to_mumble()
  {  return nullptr;  }

  virtual submumble *downcast_to_submumble()
  {  return nullptr;  }
};

class bar : public foo
{
public:

  virtual bar *downcast_to_bar()
  {  return static_cast<bar *>(this);  }
};

class mumble : public foo
{
public:

  virtual mumble *downcast_to_mumble()
  {  return static_cast<mumble *>(this);  }
};

class submumble : public mumble
{

  virtual submumble *downcast_to_submumble()
  {  return static_cast<submumble *>(this);  }
};

int main (int argc, char **argv)
{
  foo     *my_foo(new bar);
  bar     *my_bar;

  if (argc > 1)
    {
      for (long int i(1000000000); i > 0; --i)
    {
      my_bar = dynamic_cast<bar *>(my_foo);
    }
    } else {
      for (long int i(1000000000); i > 0; --i)
    {
      my_bar = my_foo->downcast_to_bar();
    }
    }

  delete my_foo;

  return 0;
}