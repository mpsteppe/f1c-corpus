HRESULT __thiscall sub_455C60(LPVOID *ppvOut)
{
  HRESULT result; // eax

  if ( dword_7C569C != 5 && (unsigned __int8)StringSplitLoop(2, aDDevF119992002_13, 5225) )
    DebugLogWrite(&dword_8AD25C, aEnteredHwinput_0);
  result = DirectInput8Create(hinst, 0x800u, &riidltf, ppvOut, 0);
  if ( !result )
  {
    D3DWindowSurfaceCreation(ppvOut + 1, (int)hWnd, (unsigned __int8)byte_5EC4A4, 2);
    DirectXDeviceInitialization(ppvOut + 866, (int)hWnd, (unsigned __int8)byte_5EC4A4);
    DirectXDeviceInitialization(ppvOut + 1121, (int)hWnd, (unsigned __int8)byte_5EC4A4);
    CollisionObjectDestructor(ppvOut + 1121);
    CollisionObjectDestructor(ppvOut + 866);
    DirectXDeviceInitialization(ppvOut + 866, (int)hWnd, (unsigned __int8)byte_5EC4A4);
    DirectXDeviceInitialization(ppvOut + 1121, (int)hWnd, (unsigned __int8)byte_5EC4A4);
    return GlobalStateInitializerWithEnumValues((int *)ppvOut);
  }
  return result;
}

