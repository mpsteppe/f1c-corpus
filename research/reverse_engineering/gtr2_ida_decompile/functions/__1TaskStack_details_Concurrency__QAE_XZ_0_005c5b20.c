void __thiscall Concurrency::details::TaskStack::~TaskStack(void **this)
{
  if ( this[2] )
    j__free(this[2]);
}
