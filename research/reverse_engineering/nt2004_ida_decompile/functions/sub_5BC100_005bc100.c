int __fastcall sub_5BC100(int a1, int a2)
{
  int result; // eax

  result = sub_5BBF60((int *)(a1 + 8), a2);
  if ( !result )
    return sub_5BBF60((int *)(a1 + 20), a2);
  return result;
}
