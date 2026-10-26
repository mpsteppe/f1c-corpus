// positive sp value has been detected, the output may be wrong!
void __thiscall sub_5E8CD7(_DWORD *this)
{
  void *v2; // eax

  `eh vector destructor iterator'(this + 218, 0x18u, 8, nullsub_7);
  `eh vector destructor iterator'(this + 151, 0x18u, 8, nullsub_7);
  `eh vector destructor iterator'(this + 84, 0x18u, 8, nullsub_7);
  v2 = (void *)this[53];
  *((_BYTE *)this + 201) = 0;
  *((_BYTE *)this + 200) = 0;
  this[52] = 0;
  if ( v2 )
    j__free(v2);
  nullsub_7(this);
}
