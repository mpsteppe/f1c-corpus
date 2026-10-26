// Function: ~exception @ 0059bfa0
// Size (bytes): 22


/* Library Function - Single Match
    public: virtual __thiscall exception::~exception(void)
   
   Libraries: Visual Studio 2003 Release, Visual Studio 2005 Release */

void __thiscall exception::~exception(exception *this)

{
  *(undefined ***)this = &PTR_FUN_005b9dc0;
  if (*(int *)(this + 8) != 0) {
    FUN_00587bcf(*(undefined4 *)(this + 4));
  }
  return;
}


