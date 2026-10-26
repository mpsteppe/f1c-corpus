int __thiscall sub_5E77B0(_DWORD *this, int a2, int a3)
{
  char v5; // [esp+0h] [ebp-4h]

  if ( (*(int (__thiscall **)(int))(*(_DWORD *)dword_FB27A4 + 164))(dword_FB27A4) )
  {
    if ( a2 == 1 )
    {
      if ( a3 == 2 )
      {
        if ( (*(int (__thiscall **)(int, _DWORD *, int, int))(*(_DWORD *)dword_FB27A4 + 320))(dword_FB27A4, this, 1, 2) )
        {
          sub_5D8C80((int)this, (char *)0xFFFFFFFF, "HW error during surface refresh.", v5);
          return -1;
        }
LABEL_10:
        *this |= 0x100u;
        return 0;
      }
    }
    else if ( a2 == 4 && a3 == 8 )
    {
      if ( (*(int (__thiscall **)(int, _DWORD *, int, int))(*(_DWORD *)dword_FB27A4 + 324))(dword_FB27A4, this, 4, 8) )
      {
        sub_5D8C80((int)this, (char *)0xFFFFFFFF, "HW error during texture refresh.", v5);
        return -1;
      }
      goto LABEL_10;
    }
    sub_5D8C80((int)this, (char *)0xFFFFFFFF, "Invalid src and/or dest surface flags for refresh.", v5);
    return -1;
  }
  else
  {
    sub_5D8C80((int)this, (char *)0xFFFFFFFF, "No HW device available for refresh.", v5);
    return -1;
  }
}
