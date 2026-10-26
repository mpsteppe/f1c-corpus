// f1c  0x004a18d0  size=90
BOOL sub_4A18D0()
{
  if ( (unsigned __int8)sub_4D7A50(2, aDDevF119992002_19, 420) )
    sub_4D7AA0(&unk_8AD25C, aEnteredOsmanEn);
  hObject = CreateMutexA(0, 1, Name);
  return !hObject || GetLastError() == 183;
}
