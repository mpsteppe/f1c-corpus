int __stdcall sub_5EA600(_BYTE *a1, int a2)
{
  _BYTE *v2; // ecx
  int v3; // esi
  char v4; // bl
  int v5; // edi
  char v6; // al
  int result; // eax
  char v8; // [esp+10h] [ebp-4h]
  int v9; // [esp+18h] [ebp+4h]

  v2 = a1;
  v3 = 0;
  v4 = -125;
  v8 = -127 - (_BYTE)a1;
  v5 = a2 - (_DWORD)a1;
  v9 = 16;
  do
  {
    if ( ((v3 % 3) & 1) != 0 )
      v6 = v4;
    else
      v6 = v8 + (_BYTE)v2;
    ++v3;
    --v4;
    v2[v5] = *v2 - v6;
    ++v2;
    result = v9 - 1;
    v9 = result;
  }
  while ( result );
  return result;
}
