int __thiscall sub_6B2515(_DWORD *this, int a2)
{
  int v3; // ebx
  int result; // eax
  int v5; // [esp+8h] [ebp-Ch] BYREF
  int v6; // [esp+Ch] [ebp-8h] BYREF
  int v7; // [esp+10h] [ebp-4h] BYREF

  v3 = *(_DWORD *)(this[5] + 4 * a2);
  if ( (unsigned __int16)this[50] > 0x100u )
  {
    if ( *(_DWORD *)(v3 + 8) == -1 || (result = sub_6B2515(*(_DWORD *)(v3 + 8)), result >= 0) )
    {
      if ( this[78] == a2 )
      {
        return 0;
      }
      else
      {
        result = sub_6CB0CE(1);
        if ( result >= 0 )
        {
          result = (*(int (__thiscall **)(_DWORD *, int, int, _DWORD))(*this + 100))(this, -1342177280, 0x10000, 0);
          if ( result >= 0 )
          {
            result = (*(int (__thiscall **)(_DWORD *, int, int *, int *))(*this + 116))(this, v3, &v5, &v7);
            if ( result >= 0 )
            {
              result = (*(int (__thiscall **)(_DWORD *, int *, int, int, int *))(*this + 120))(
                         this,
                         &a2,
                         1,
                         0x10000,
                         &v6);
              if ( result >= 0 )
              {
                result = (*(int (__thiscall **)(_DWORD *, int, int, int))(*this + 104))(this, v5, v6, v7);
                if ( result >= 0 )
                {
                  result = (*(int (__thiscall **)(_DWORD *))(*this + 96))(this);
                  if ( result >= 0 )
                  {
                    result = sub_6C64E6(this);
                    if ( result >= 0 )
                    {
                      this[78] = a2;
                      return 0;
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  else
  {
    sub_686791(
      (int)this,
      *(_DWORD *)(this[64] + 60),
      4511,
      "relative addressing not supported in vs_1_0 instruction set");
    return -2147467263;
  }
  return result;
}
