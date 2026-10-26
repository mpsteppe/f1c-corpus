// f1c  0x00449a20  size=89
int __thiscall sub_449A20(const CHAR *this)
{
  int result; // eax
  int v2; // esi
  DWORD v3; // edi
  DWORD TotalBytesAvail[9]; // [esp+4h] [ebp-24h] BYREF

  result = sub_595AE2(this, 0);
  v2 = result;
  if ( result != -1 )
  {
    if ( sub_59B760(result, (DWORD)TotalBytesAvail) )
    {
      sub_58C331(v2);
      return -1;
    }
    else
    {
      v3 = TotalBytesAvail[7];
      sub_58C331(v2);
      return v3;
    }
  }
  return result;
}
