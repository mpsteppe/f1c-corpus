int __thiscall sub_494ED0(_DWORD *this)
{
  char v1; // bl
  int v2; // edi
  int v3; // eax
  const char *v4; // eax
  char *v5; // eax
  int result; // eax
  char v7; // [esp+Ch] [ebp-4h]

  v1 = 1;
  v2 = -1;
  v7 = 1;
  if ( this[69] == 100 )
  {
    v1 = 0;
    v7 = 0;
    v2 = 0;
  }
  v3 = sub_54C880(&unk_BE27B0, v7);
  if ( v3 )
  {
    v4 = (const char *)sub_54B440(v3);
    v5 = sub_41D840(&byte_91CC38, v4);
    sub_615860(v5);
    sub_4CD6D0("JOIN FAILURE PAGE");
    return -1;
  }
  else
  {
    result = v2;
    if ( v1 )
      dword_75B17C = 1;
  }
  return result;
}
