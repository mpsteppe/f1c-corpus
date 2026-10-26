// f1c  0x0048a8d0  size=280
int __thiscall sub_48A8D0(float *this)
{
  int v2; // eax
  int v3; // eax
  int v4; // edi
  int v5; // edi
  int v7; // [esp+4h] [ebp-8h] BYREF
  _BYTE v8[4]; // [esp+8h] [ebp-4h] BYREF

  sub_498880(v8, &v7);
  this[82] = sub_498940(*((_DWORD *)this + 16));
  (*(void (__thiscall **)(float *, int))(*(_DWORD *)this + 44))(this, 1);
  if ( *((_BYTE *)this + 326) && *((int *)this + 88) > 0 )
  {
    v2 = (*(int (__thiscall **)(float *))(*(_DWORD *)this + 28))(this);
    v3 = v7 - *((_DWORD *)this + 87) / 2 - v2;
    *((_DWORD *)this + 84) = v3;
    if ( v3 < 0 )
      this[84] = 0.0;
    v4 = (*(int (__thiscall **)(float *))(*(_DWORD *)this + 36))(this) - *((_DWORD *)this + 87);
    if ( *((_DWORD *)this + 84) > v4 - (*(int (__thiscall **)(float *))(*(_DWORD *)this + 28))(this) )
    {
      v5 = (*(int (__thiscall **)(float *))(*(_DWORD *)this + 36))(this) - *((_DWORD *)this + 87);
      *((_DWORD *)this + 84) = v5 - (*(int (__thiscall **)(float *))(*(_DWORD *)this + 28))(this);
    }
    sub_489EE0(this);
  }
  if ( this[82] > 0.25 && this[82] > 0.2 )
  {
    if ( *((_BYTE *)this + 324) )
    {
      sub_489500(this);
      return 0;
    }
    if ( *((_BYTE *)this + 325) )
      sub_489530(this);
  }
  return 0;
}
