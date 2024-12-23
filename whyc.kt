fun main(){
    val shapes: MutableList<String> = mutableListOf("Triangle", "Square")

    println("Circle" in shapes)

    shapes.add("Circle")

    println("Circle" in shapes)
}