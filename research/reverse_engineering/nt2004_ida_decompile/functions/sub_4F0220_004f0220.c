int __stdcall sub_4F0220(unsigned int a1, int a2)
{
  int result; // eax
  const char *v3; // eax
  _DWORD v4[2]; // [esp+10h] [ebp-118h] BYREF
  int v5; // [esp+18h] [ebp-110h]
  int v6; // [esp+1Ch] [ebp-10Ch]
  char v7; // [esp+20h] [ebp-108h]
  char Buffer[260]; // [esp+24h] [ebp-104h] BYREF

  if ( !dword_7D6BB0 )
  {
LABEL_4:
    result = dword_7D6BC0;
    if ( !dword_7D6BC0 )
      return result;
    goto LABEL_5;
  }
  result = dword_7D6BC0;
  if ( !dword_7D6BC0 )
  {
    dword_7D6BC0 = (*(int (**)(void))(*(_DWORD *)dword_7D6BB0 + 100))();
    goto LABEL_4;
  }
LABEL_5:
  if ( a1 <= 8 )
  {
    v4[0] = 0;
    v4[1] = -1;
    sub_578600(&byte_629120);
    v3 = *(const char **)dword_62A070;
    v5 = -1;
    v6 = -1;
    v7 = 0;
    if ( !*(_DWORD *)dword_62A070 )
      v3 = &byte_629120;
    sprintf(Buffer, "%s%s", v3, off_61110C[a1]);
    sub_578600(Buffer);
    v5 = -1;
    v6 = -1;
    v7 = 0;
    (*(void (__thiscall **)(int, int))(*(_DWORD *)dword_7D6BC0 + 32))(dword_7D6BC0, a2);
    (*(void (__thiscall **)(int, _DWORD *, int, _DWORD))(*(_DWORD *)dword_7D6BC0 + 4))(dword_7D6BC0, v4, 1, 0);
    result = v4[0];
    if ( v4[0] )
      return sub_5BE8AE();
  }
  return result;
}
