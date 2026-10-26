int __thiscall sub_4E8550(int *this)
{
  int result; // eax
  int v3; // eax
  int v4; // edi
  int v5; // eax
  float v6; // [esp+10h] [ebp-14h]
  char Buffer[16]; // [esp+14h] [ebp-10h] BYREF

  result = this[104];
  v6 = *((float *)dword_91E07C + 4299);
  if ( result )
  {
    if ( this[99] )
    {
      v3 = this[100];
      if ( v3 )
      {
        if ( v3 == 1 )
        {
          v4 = this[1];
        }
        else if ( v3 == 2 )
        {
          v4 = *this;
        }
        else
        {
          v4 = *((_DWORD *)dword_91E07C + 4299);
        }
      }
      else
      {
        v4 = this[2];
      }
      sub_4E6210((int)"G", this[102], this[103], v4, this[3], this[101]);
    }
    else
    {
      v4 = *((_DWORD *)dword_91E07C + 4299);
    }
    if ( dword_B72454 == 1 )
      sprintf(Buffer, " %.0f", v6 * 0.26417205);
    else
      sprintf(Buffer, " %.0f", v6);
    v5 = this[105];
    if ( v5 )
    {
      if ( v5 == 1 )
      {
        v4 = this[1];
      }
      else if ( v5 == 2 )
      {
        v4 = *this;
      }
    }
    else
    {
      v4 = this[2];
    }
    return sub_4E6210((int)Buffer, this[107], this[108], v4, this[3], this[106]);
  }
  return result;
}
