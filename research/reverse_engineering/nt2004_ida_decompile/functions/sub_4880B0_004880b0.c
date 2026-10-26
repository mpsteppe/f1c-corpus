unsigned __int8 __stdcall sub_4880B0(int a1)
{
  unsigned __int8 result; // al

  result = byte_769AD8 == 0;
  byte_769AD8 = byte_769AD8 == 0;
  if ( (unsigned __int8)byte_769AD8 >= (unsigned __int8)byte_769ADA )
  {
    if ( result > (unsigned __int8)byte_769ADB )
      byte_769AD8 = byte_769ADB;
  }
  else
  {
    byte_769AD8 = byte_769ADA;
  }
  return result;
}
