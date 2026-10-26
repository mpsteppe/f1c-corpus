int __usercall sub_4AA210@<eax>(int a1@<ecx>, int a2@<ebp>)
{
  char *v2; // ebp
  _DWORD *v3; // eax
  int v4; // edi
  int v5; // ebx
  int v6; // esi
  const char *v7; // eax
  char *v8; // eax
  _DWORD Buffer[66]; // [esp+0h] [ebp-108h] BYREF

  Buffer[0] = a2;
  Buffer[1] = a1;
  v2 = 0;
  v3 = (_DWORD *)sub_616840("Game Name");
  if ( v3 )
    v2 = sub_48D380(v3);
  v4 = sub_5387C0(&unk_BE1CFC);
  v5 = 0;
  v6 = 0;
  if ( v4 < 0 )
    goto LABEL_11;
  do
  {
    if ( (unsigned __int8)sub_53A120() )
    {
      v7 = (const char *)sub_5387F0(&unk_BE1CFC, v6, v6);
      if ( v7 )
      {
        v8 = sub_41D840(&byte_91CC38, v7);
        sub_41D810((char *)Buffer, 0x7Fu, "%s", v8);
      }
      ++v5;
    }
    ++v6;
  }
  while ( v6 <= v4 );
  if ( v5 <= 1 )
LABEL_11:
    JUMPOUT(0x4AA2BD);
  return sub_458036(v2);
}
