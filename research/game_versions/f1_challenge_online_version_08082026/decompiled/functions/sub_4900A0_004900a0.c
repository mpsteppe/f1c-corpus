int __thiscall sub_4900A0(_DWORD *this)
{
  int v2; // edi
  int v3; // ebx
  int v4; // ebp
  int v5; // eax
  int v6; // eax
  int v8; // [esp+10h] [ebp-Ch] BYREF
  int v9; // [esp+14h] [ebp-8h] BYREF
  int v10; // [esp+18h] [ebp-4h]

  v8 = 0;
  v9 = 0;
  v2 = sub_487060(this, 0);
  v3 = sub_487060(this, 1);
  v4 = sub_4870E0(this, 0);
  v10 = sub_4870E0(this, 1);
  sub_498880(&v8, &v9);
  if ( v8 > v2 && v8 < v3 && v9 > v4 && v9 < v10 )
  {
    v5 = this[56];
    if ( !v5 )
      goto LABEL_10;
    v6 = v5 - 1;
    if ( !v6 )
    {
      this[56] = 0;
      goto LABEL_11;
    }
    if ( v6 != 1 )
    {
LABEL_10:
      this[56] = 1;
      goto LABEL_11;
    }
    this[56] = 2;
  }
LABEL_11:
  (*(void (__thiscall **)(_DWORD *, _DWORD))(*this + 64))(this, this[56]);
  (*(void (__thiscall **)(_DWORD *))(*this + 152))(this);
  return 0;
}
