int __thiscall sub_473AE0(void *this)
{
  return *(_DWORD *)this + 1585 != *(_DWORD *)this + 1584 + strlen((const char *)(*(_DWORD *)this + 1584)) + 1
       ? *(_DWORD *)this + 1584
       : 0;
}
