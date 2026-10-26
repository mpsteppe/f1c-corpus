int __thiscall sub_4884A0(_BYTE *this)
{
  int v2; // eax
  int v3; // edx
  int v5; // [esp+4h] [ebp-8h] BYREF
  int v6; // [esp+8h] [ebp-4h] BYREF

  v5 = 0;
  v6 = 0;
  sub_4AE870(&v5, &v6);
  if ( v5 > sub_49D770(0) && v5 < sub_49D770(1) && v6 > sub_49D7F0(0) && v6 < sub_49D7F0(1) )
  {
    switch ( sub_49D1E0(this) )
    {
      case 0:
      case 1:
      case 2:
      case 3:
      case 4:
      case 6:
        v2 = *(_DWORD *)this;
        this[816] = 0;
        (*(void (__thiscall **)(_BYTE *, int))(v2 + 44))(this, 5);
        break;
      case 5:
        v3 = *(_DWORD *)this;
        this[816] = 1;
        (*(void (__thiscall **)(_BYTE *, int))(v3 + 44))(this, 2);
        break;
      default:
        break;
    }
    sub_488BA0(this);
  }
  if ( sub_49D1E0(this) == 5 )
    return 0;
  else
    return sub_4A24A0(this);
}
