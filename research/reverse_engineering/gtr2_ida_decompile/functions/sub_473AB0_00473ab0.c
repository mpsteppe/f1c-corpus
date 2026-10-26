int __thiscall sub_473AB0(void *this)
{
  return *(_DWORD *)this + 1505 != *(_DWORD *)this + 1504 + strlen((const char *)(*(_DWORD *)this + 1504)) + 1
       ? *(_DWORD *)this + 1504
       : 0;
}
