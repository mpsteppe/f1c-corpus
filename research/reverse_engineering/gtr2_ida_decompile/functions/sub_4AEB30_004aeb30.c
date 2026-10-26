int __thiscall sub_4AEB30(_DWORD *this)
{
  int v1; // edx
  int v2; // eax
  int v3; // edx
  const CHAR *v4; // eax
  int result; // eax
  const CHAR *v6; // eax
  const CHAR *v7; // eax
  _BYTE v8[8]; // [esp+0h] [ebp-40Ch] BYREF
  _BYTE v9[1028]; // [esp+8h] [ebp-404h] BYREF

  if ( byte_B722E4 )
  {
    dword_B72414 = dword_B723CC;
    if ( dword_B723CC >= (unsigned int)dword_B7241C )
    {
      if ( dword_B723CC > (unsigned int)dword_B72420 )
        dword_B72414 = dword_B72420;
    }
    else
    {
      dword_B72414 = dword_B7241C;
    }
  }
  else if ( *(_DWORD *)dword_B72314 != 4 )
  {
    v1 = dword_B723F8;
    dword_B723F0 = dword_B723CC;
    if ( dword_B723CC < (unsigned int)dword_B723F8 || (v1 = dword_B723FC, dword_B723CC > (unsigned int)dword_B723FC) )
      dword_B723F0 = v1;
  }
  v2 = dword_B723D4;
  dword_B723CC = dword_B723F0;
  if ( dword_B723F0 < (unsigned int)dword_B723D4 || (v2 = dword_B723D8, dword_B723F0 > (unsigned int)dword_B723D8) )
    dword_B723CC = v2;
  v3 = dword_B7231C;
  *(_DWORD *)dword_B72314 = this[69];
  if ( *(int *)dword_B72314 < dword_B7231C || (v3 = dword_B72320, *(int *)dword_B72314 > dword_B72320) )
    *(_DWORD *)dword_B72314 = v3;
  byte_B722E4 = 0;
  if ( byte_B722E6 )
    byte_B722E4 = byte_B722E6;
  switch ( this[69] )
  {
    case 1:
    case 2:
    case 3:
    case 5:
    case 7:
      v6 = (const CHAR *)dword_B72394;
      if ( !dword_B72394 )
        v6 = WindowName;
      sub_5100A0(&byte_B6F530, v6);
      sub_53B0D0(&unk_BE1CFC, v9, 1023);
      sub_53BDE0(&unk_BE1CE0, v8);
      v7 = (const CHAR *)dword_B6F724;
      if ( !dword_B6F724 )
        v7 = WindowName;
      sub_615860(v7);
      goto LABEL_27;
    case 4:
      v4 = Str;
      if ( !Str )
        v4 = WindowName;
      sub_5100A0(&byte_B6F530, v4);
      result = 0;
      break;
    default:
LABEL_27:
      result = 0;
      break;
  }
  return result;
}
