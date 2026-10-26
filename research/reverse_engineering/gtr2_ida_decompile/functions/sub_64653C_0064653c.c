int __thiscall sub_64653C(char *this, _DWORD *a2)
{
  _DWORD *v3; // edx
  void *v4; // eax
  int v5; // eax

  if ( *((_DWORD *)this + 1) && *((_DWORD *)this + 14) )
    j__free(*((void **)this + 1));
  if ( *((_DWORD *)this + 2) && *((_DWORD *)this + 15) )
    j__free(*((void **)this + 2));
  *(_DWORD *)this = a2[1];
  *((_DWORD *)this + 1) = *a2;
  *((_DWORD *)this + 2) = a2[20];
  v3 = this + 24;
  qmemcpy(this + 24, a2 + 10, 0x18u);
  *((_DWORD *)this + 12) = a2[2];
  *((_DWORD *)this + 13) = a2[3];
  v4 = *(void **)this;
  if ( *(int *)this <= 877942852 )
  {
    if ( *(_DWORD *)this == 877942852 || v4 == (void *)827611204 || v4 == (void *)844388420 )
      goto LABEL_13;
    if ( v4 != (void *)844715353 )
    {
      if ( v4 == (void *)861165636 )
      {
LABEL_13:
        *v3 &= 0xFFFFFFFC;
        *((_DWORD *)this + 7) &= 0xFFFFFFFC;
        goto LABEL_14;
      }
      goto LABEL_14;
    }
LABEL_19:
    *v3 &= ~1u;
    goto LABEL_14;
  }
  if ( v4 == (void *)894720068 )
    goto LABEL_13;
  if ( v4 == (void *)1111970375 || v4 == (void *)1195525970 || v4 == (void *)1498831189 )
    goto LABEL_19;
LABEL_14:
  v5 = *((_DWORD *)this + 8) - *v3;
  *((_DWORD *)this + 14) = 0;
  *((_DWORD *)this + 15) = 0;
  *((_DWORD *)this + 3) = v5;
  *((_DWORD *)this + 4) = *((_DWORD *)this + 9) - *((_DWORD *)this + 7);
  *((_DWORD *)this + 5) = *((_DWORD *)this + 11) - *((_DWORD *)this + 10);
  return 0;
}
