int __thiscall sub_481B30(void *this)
{
  char *v2; // eax
  int v3; // edi
  int v5; // [esp+8h] [ebp-8h] BYREF
  int v6; // [esp+Ch] [ebp-4h] BYREF

  v5 = 0;
  v6 = 0;
  sub_4AE870(&v5, &v6);
  if ( v5 > sub_49D770(0) && v5 < sub_49D770(1) && v6 > sub_49D7F0(0) && v6 < sub_49D7F0(1) )
  {
    v2 = (char *)sub_49D1F0(0);
    if ( v2 )
    {
      v3 = sub_4AD520(v2);
      if ( v3 )
      {
        switch ( sub_49D1E0(this) )
        {
          case 0:
          case 1:
          case 2:
          case 3:
          case 4:
          case 6:
            (*(void (__thiscall **)(void *, int))(*(_DWORD *)this + 44))(this, 5);
            (*(void (__thiscall **)(int, int))(*(_DWORD *)v3 + 40))(v3, 1);
            break;
          case 5:
            (*(void (__thiscall **)(void *, int))(*(_DWORD *)this + 44))(this, 2);
            (*(void (__thiscall **)(int, _DWORD))(*(_DWORD *)v3 + 40))(v3, 0);
            break;
          default:
            break;
        }
      }
    }
  }
  if ( sub_49D1E0(this) == 5 )
    return 0;
  else
    return sub_4A24A0(this);
}
