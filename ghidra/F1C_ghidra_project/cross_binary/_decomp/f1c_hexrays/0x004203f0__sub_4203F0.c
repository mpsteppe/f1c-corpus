// f1c  0x004203f0  size=150
char **sub_4203F0()
{
  char **result; // eax
  char **v1; // esi
  char *v2; // ecx
  int v3; // eax
  int v4; // esi
  int v5; // edi
  int v6; // eax
  int v7; // ebx
  int v8; // eax
  _DWORD v9[8]; // [esp+4h] [ebp-20h] BYREF

  result = (char **)sub_41E920(0, 0);
  v1 = result;
  if ( result )
  {
    v2 = *result;
    if ( !*result )
      v2 = &byte_5EA438;
    v3 = sub_41E920((int)v2, 1);
    v4 = (int)v1[102];
    v5 = *(_DWORD *)(v3 + 408);
    v6 = sub_4C2850(&unk_7D2DB0);
    v7 = sub_4C11D0(v6);
    v8 = sub_4C2850(&unk_7D2DB0);
    result = (char **)(v5 + 10 * (sub_4C1190(v8) - v7));
    if ( (int)result >= v4
      && ((int)result < v4 + 1
       || (int)result < v4 + 2
       || (int)result < v4 + 3
       || (int)result < v4 + 4
       || (int)result < v4 + 6) )
    {
      return (char **)sub_4144D0(v9);
    }
  }
  return result;
}
