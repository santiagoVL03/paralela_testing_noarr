# Recorrido Paralelo Optimizado de Estructuras de Datos en C++

### **Descripción**
Este repositorio presenta una **abstracción** para el recorrido optimizado de estructuras de datos regulares (como matrices multidimensionales) usando **C++ puro**. La solución se basa en una extensión de la biblioteca **Noarr**, permitiendo un diseño **agnóstico al recorrido** y adaptable para optimizaciones de memoria y ejecución paralela en CPU y GPU (TBB y CUDA).

---

## **Características Principales**
1. **Optimización de memoria**:
   - Ajuste del orden de recorrido para aprovechar cachés y prefetching.
   - Transformaciones como **tiling**, strip-mining y z-curves.

2. **Diseño agnóstico al recorrido**:
   - Separación entre lógica algorítmica y orden de acceso a memoria.
   - Transformaciones reutilizables y componibles.

3. **Paralelización eficiente**:
   - Compatible con **TBB** para CPU multicore.
   - Adaptación a **CUDA** para ejecución en GPU.
   - Soporte para memoria compartida y privatización en CUDA.

4. **Compatibilidad total**:
   - Implementado en **C++ estándar** usando meta-programación de templates.
   - Compilable con GCC y NVCC (para CUDA).


