int __thiscall sub_4D3330(_DWORD *this)
{
  int v2; // edi
  int v3; // ebx
  int v4; // ebp
  int v6; // [esp+10h] [ebp-Ch] BYREF
  int v7; // [esp+14h] [ebp-8h] BYREF
  int v8; // [esp+18h] [ebp-4h]

  v6 = 0;
  v7 = 0;
  v2 = sub_4CFCC0(this, 0);
  v3 = sub_4CFCC0(this, 1);
  v4 = sub_4CFD30(this, 0);
  v8 = sub_4CFD30(this, 1);
  sub_4DE540(&v6, &v7);
  if ( v6 > v2 && v6 < v3 && v7 > v4 && v7 < v8 )
  {
    switch ( this[67] )
    {
      case 1:
        this[67] = 0;
        break;
      case 4:
        this[67] = 4;
        break;
      case 5:
        this[67] = 5;
        break;
      default:
        this[67] = 1;
        break;
    }
  }
  (*(void (__thiscall **)(_DWORD *, _DWORD))(*this + 44))(this, this[67]);
  (*(void (__thiscall **)(_DWORD *))(*this + 144))(this);
  return 0;
}
