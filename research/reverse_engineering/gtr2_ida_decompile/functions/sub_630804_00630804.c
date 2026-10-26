exception *__thiscall sub_630804(exception *this, struct exception *a2)
{
  exception::exception(this, a2);
  *(_DWORD *)this = &std::bad_alloc::`vftable';
  return this;
}
