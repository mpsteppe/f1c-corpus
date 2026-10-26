char sub_46F0E0()
{
  if ( !dword_765590 )
  {
    if ( !sub_5A29F0((int)&dword_765590, aRendertargette, 512, 512, 8, 0, 262152, 1) )
    {
      if ( !sub_5A1A60(&dword_765594, 2, dword_765590, 48, 3136) )
        return 1;
      sub_5A2B00(dword_765590);
      dword_765594 = 0;
    }
    dword_765590 = 0;
  }
  return 0;
}
