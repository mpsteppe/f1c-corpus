void __thiscall sub_59DA50(void *this, float a2)
{
  double v3; // st7
  bool v4; // zf
  void *v5; // eax
  int v6; // edi
  float v7; // eax
  int v8; // eax
  void *v9; // esi
  int v10; // [esp+14h] [ebp-30h]
  _DWORD v11[8]; // [esp+18h] [ebp-2Ch] BYREF
  int v12; // [esp+40h] [ebp-4h]
  bool v13; // [esp+48h] [ebp+4h]

  v3 = *((float *)this + 689) - a2;
  *((float *)this + 689) = v3;
  if ( v3 <= 0.0 )
  {
    *((_DWORD *)this + 689) = 1040187392;
    v4 = sub_5A4330(this) == 4;
    v5 = (void *)*((_DWORD *)this + 701);
    v13 = !v4;
    if ( v5 )
      WaitForSingleObject(v5, *((_DWORD *)this + 702));
    v6 = 0;
    v10 = (*(int (__thiscall **)(void *))(*(_DWORD *)this + 164))(this);
    if ( v10 > 0 )
    {
      do
      {
        sub_5A6CF0(v11, 0, 0, 0);
        v11[0] = &off_725FFC;
        v11[7] = 0;
        v7 = *(float *)this;
        v12 = 0;
        if ( (*(unsigned __int8 (__thiscall **)(void *, int, _DWORD *))(LODWORD(v7) + 176))(this, v6, v11)
          && (!v13 || sub_6442E0(v11) == 2) )
        {
          v8 = sub_5A6E90(v11);
          sub_5A4A00(v8, 0);
        }
        v11[0] = &off_725FFC;
        v12 = -1;
        sub_5A6D70(v11);
        ++v6;
      }
      while ( v6 < v10 );
    }
    sub_59CC90();
    v9 = (void *)*((_DWORD *)this + 701);
    if ( v9 )
      ReleaseMutex(v9);
  }
}
