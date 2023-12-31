FROM gcc:latest
WORKDIR /usr/src/myapp
COPY Project_24_AD.cpp .
RUN g++ -o myapp Project_24_AD.cpp -lstdc++
CMD ["./myapp"]