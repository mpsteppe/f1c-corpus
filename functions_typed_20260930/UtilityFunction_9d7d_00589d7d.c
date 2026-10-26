void __cdecl sub_589D7D(void (**a1)(void), unsigned int a2)
{
  while ( (unsigned int)a1 < a2 )
  {
    if ( *a1 )
      (*a1)();
    ++a1;
  }
}

