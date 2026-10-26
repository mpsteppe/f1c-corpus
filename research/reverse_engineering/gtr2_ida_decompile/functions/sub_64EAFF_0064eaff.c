void __thiscall sub_64EAFF(void *this)
{
  void *v2; // [esp-4h] [ebp-8h]

  v2 = (void *)*((_DWORD *)this + 14);
  *(_DWORD *)this = &off_7374D0;
  j__free(v2);
  j__free(*((void **)this + 22));
  j__free(*((void **)this + 23));
}
