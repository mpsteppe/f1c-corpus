void __thiscall Concurrency::details::TaskStack::~TaskStack(Concurrency::details::TaskStack *this)
{
  if ( *((_DWORD *)this + 2) )
    sub_5BE8AE();
}
