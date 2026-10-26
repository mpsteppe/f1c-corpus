void __thiscall Concurrency::details::_RefCounter::_Destroy(Concurrency::details::_RefCounter *this)
{
  if ( this )
    (**(void (__thiscall ***)(Concurrency::details::_RefCounter *, int))this)(this, 1);
}
